we have a python script that is using `exec` function to execute hex obfuscated code

let's first execute the script before proceeding with the deobfuscation

```bash
┌──(kali㉿kali)-[~/ctf/sicsCTF2024/crypto/master]
└─$ python obfuscation.py
Please enter the password: anything
Wrong password :(
```

so it's asking for the password but we don't anything about how its doing the check, so let's dig deep into the `deobfuscation`

we have hex code so let's unhex it using cyberchef

[![image.png](https://i.postimg.cc/HL7jcT1y/image.png)](https://postimg.cc/kVq7L34J)

and we have a python script

```python
import base64

code = "\x59\x32\x39\x6b\x5a\x53\x41\x39\x49\x43\x4a\x63\x65\x44\x42\x69\x58\x48\x67\x32\x59\x6c\x78\x34\x4e\x6a\x56\x63\x65\x44\x49\x30\x58\x48\x67\x32\x59\x31\x78\x34\x4e\x6a\x68\x63\x65\x44\x63\x78\x58\x48\x67\x33\x4e\x31\x78\x34\x4e\x7a\x64\x63\x65\x44\x4a\x6a\x58\x48\x67\x79\x4d\x6c\x78\x34\x4e\x54\x5a\x63\x65\x44\x5a\x6b\x58\x48\x67\x32\x4e\x31\x78\x34\x4e\x6a\x4a\x63\x65\x44\x63\x33\x58\x48\x67\x32\x4d\x46\x78\x34\x4d\x6a\x5a\x63\x65\x44\x59\x30\x58\x48\x67\x32\x59\x31\x78\x34\x4e\x7a\x64\x63\x65\x44\x59\x78\x58\x48\x67\x33\x4e\x31\x78\x34\x4d\x6a\x5a\x63\x65\x44\x63\x31\x58\x48\x67\x32\x59\x56\x78\x34\x4e\x6a\x5a\x63\x65\x44\x49\x30\x58\x48\x67\x33\x4e\x56\x78\x34\x4e\x6a\x64\x63\x65\x44\x63\x79\x58\x48\x67\x33\x4d\x56\x78\x34\x4e\x7a\x52\x63\x65\x44\x5a\x69\x58\x48\x67\x33\x4e\x31\x78\x34\x4e\x6a\x4a\x63\x65\x44\x4e\x69\x58\x48\x67\x79\x4d\x6c\x78\x34\x4d\x6a\x52\x63\x65\x44\x4a\x6b\x58\x48\x67\x79\x4e\x56\x78\x34\x4d\x32\x4a\x63\x65\x44\x4e\x6a\x58\x48\x67\x79\x4d\x6c\x78\x34\x4d\x6a\x52\x63\x65\x44\x51\x77\x58\x48\x67\x30\x4d\x46\x78\x34\x4e\x44\x42\x63\x65\x44\x51\x30\x58\x48\x67\x30\x59\x31\x78\x34\x4e\x54\x42\x63\x65\x44\x56\x6b\x58\x48\x67\x31\x4e\x6c\x78\x34\x4e\x32\x52\x63\x65\x44\x63\x35\x58\x48\x67\x7a\x4d\x6c\x78\x34\x4e\x7a\x46\x63\x65\x44\x56\x69\x58\x48\x67\x32\x4d\x46\x78\x34\x4e\x6a\x68\x63\x65\x44\x59\x79\x58\x48\x67\x7a\x4d\x6c\x78\x34\x4e\x6a\x64\x63\x65\x44\x4d\x31\x58\x48\x67\x32\x59\x6c\x78\x34\x4e\x6a\x46\x63\x65\x44\x56\x6c\x58\x48\x67\x32\x5a\x6c\x78\x34\x4e\x6a\x4a\x63\x65\x44\x63\x33\x58\x48\x67\x7a\x4d\x6c\x78\x34\x4e\x6a\x4e\x63\x65\x44\x63\x7a\x58\x48\x67\x33\x5a\x6c\x78\x34\x4d\x6a\x52\x63\x65\x44\x4e\x6c\x58\x48\x67\x77\x5a\x6c\x78\x34\x4d\x6a\x5a\x63\x65\x44\x49\x78\x58\x48\x67\x79\x4d\x6c\x78\x34\x4d\x6a\x4e\x63\x65\x44\x63\x30\x58\x48\x67\x33\x4e\x31\x78\x34\x4e\x6d\x5a\x63\x65\x44\x5a\x6d\x58\x48\x67\x33\x4e\x6c\x78\x34\x4d\x6d\x4a\x63\x65\x44\x49\x7a\x58\x48\x67\x31\x59\x31\x78\x34\x4e\x6a\x6c\x63\x65\x44\x63\x30\x58\x48\x67\x79\x4d\x6c\x78\x34\x4e\x6a\x4a\x63\x65\x44\x63\x32\x58\x48\x67\x32\x4d\x46\x78\x34\x4d\x6a\x5a\x63\x65\x44\x59\x34\x58\x48\x67\x32\x59\x31\x78\x34\x4d\x6a\x4a\x63\x65\x44\x49\x30\x58\x48\x67\x7a\x5a\x6c\x78\x34\x4d\x6d\x5a\x63\x65\x44\x49\x32\x58\x48\x67\x79\x59\x6c\x78\x34\x4d\x44\x6c\x63\x65\x44\x59\x78\x58\x48\x67\x32\x4f\x56\x78\x34\x4e\x7a\x56\x63\x65\x44\x59\x30\x58\x48\x67\x7a\x4f\x46\x78\x34\x4d\x44\x6c\x63\x65\x44\x49\x30\x58\x48\x67\x79\x4e\x56\x78\x34\x4d\x6a\x5a\x63\x65\x44\x49\x78\x58\x48\x67\x33\x4d\x6c\x78\x34\x4e\x7a\x46\x63\x65\x44\x5a\x6b\x58\x48\x67\x32\x59\x6c\x78\x34\x4e\x7a\x4a\x63\x65\x44\x49\x35\x58\x48\x67\x79\x4e\x56\x78\x34\x4e\x54\x52\x63\x65\x44\x63\x32\x58\x48\x67\x32\x59\x56\x78\x34\x4e\x6a\x68\x63\x65\x44\x59\x32\x58\x48\x67\x79\x4d\x6c\x78\x34\x4e\x7a\x4e\x63\x65\x44\x59\x31\x58\x48\x67\x33\x4e\x6c\x78\x34\x4e\x7a\x56\x63\x65\x44\x63\x32\x58\x48\x67\x32\x5a\x46\x78\x34\x4e\x7a\x46\x63\x65\x44\x59\x77\x58\x48\x67\x79\x4e\x56\x78\x34\x4d\x32\x4e\x63\x65\x44\x49\x35\x58\x48\x67\x79\x4e\x56\x78\x34\x4d\x6d\x46\x63\x65\x44\x42\x6c\x49\x69\x42\x63\x62\x6d\x74\x6c\x65\x53\x41\x39\x49\x43\x4a\x63\x65\x44\x41\x78\x58\x48\x67\x77\x4d\x6c\x78\x34\x4d\x44\x4e\x63\x65\x44\x41\x30\x58\x48\x67\x77\x4e\x56\x78\x34\x4d\x44\x59\x69\x58\x47\x35\x6c\x65\x47\x56\x6a\x4b\x43\x49\x69\x4c\x6d\x70\x76\x61\x57\x34\x6f\x57\x32\x4e\x6f\x63\x69\x68\x76\x63\x6d\x51\x6f\x59\x79\x6c\x65\x62\x33\x4a\x6b\x4b\x47\x74\x6c\x65\x56\x74\x70\x4a\x57\x78\x6c\x62\x69\x68\x72\x5a\x58\x6b\x70\x58\x53\x6b\x70\x49\x47\x5a\x76\x63\x69\x42\x70\x4c\x47\x4d\x67\x61\x57\x34\x67\x5a\x57\x35\x31\x62\x57\x56\x79\x59\x58\x52\x6c\x4b\x47\x4e\x76\x5a\x47\x55\x70\x58\x53\x6b\x70"

exec(base64.b64decode(code).decode().replace("\\n", "\n"))
```

if we execute it will do the same prompt us to enter a password, we have a again a hex obfuscated code let's unhex it using cyberchef

[![image.png](https://i.postimg.cc/FsQ6wpK5/image.png)](https://postimg.cc/0rcZwpmc)

once we unhex it we get base64 encoded code again decoding the base64 and we get 

[![image.png](https://i.postimg.cc/PJn6sfTz/image.png)](https://postimg.cc/62zVCX7y)

let's remove the `\n` and isolate each line to make it more readable

```python
code = "\x0b\x6b\x65\x24\x6c\x68\x71\x77\x77\x2c\x22\x56\x6d\x67\x62\x77\x60\x26\x64\x6c\x77\x61\x77\x26\x75\x6a\x66\x24\x75\x67\x72\x71\x74\x6b\x77\x62\x3b\x22\x24\x2d\x25\x3b\x3c\x22\x24\x40\x40\x40\x44\x4c\x50\x5d\x56\x7d\x79\x32\x71\x5b\x60\x68\x62\x32\x67\x35\x6b\x61\x5e\x6f\x62\x77\x32\x63\x73\x7f\x24\x3e\x0f\x26\x21\x22\x23\x74\x77\x6f\x6f\x76\x2b\x23\x5c\x69\x74\x22\x62\x76\x60\x26\x68\x6c\x22\x24\x3f\x2f\x26\x2b\x09\x61\x69\x75\x64\x38\x09\x24\x25\x26\x21\x72\x71\x6d\x6b\x72\x29\x25\x54\x76\x6a\x68\x66\x22\x73\x65\x76\x75\x76\x6d\x71\x60\x25\x3c\x29\x25\x2a\x0e"

key = "\x01\x02\x03\x04\x05\x06"

exec("".join([chr(ord(c)^ord(key[i%len(key)])) for i,c in enumerate(code)]))
```

analyzing this code we have an encrypted code and key used to encrypt the code and the logic being used to encrypt the code with the key, using all these we can reverse the logic and get the actual code

since it does xoring byte by byte with the key repeatedly we can simply xor it again with the key repeatedly to get the actual code `(code ^ key = encryptedCode => encryptedCode ^ key = code)` 

let's remove the `exec` and replace it with the `print` function to get the code instead of executing it

```python
code = "\x0b\x6b\x65\x24\x6c\x68\x71\x77\x77\x2c\x22\x56\x6d\x67\x62\x77\x60\x26\x64\x6c\x77\x61\x77\x26\x75\x6a\x66\x24\x75\x67\x72\x71\x74\x6b\x77\x62\x3b\x22\x24\x2d\x25\x3b\x3c\x22\x24\x40\x40\x40\x44\x4c\x50\x5d\x56\x7d\x79\x32\x71\x5b\x60\x68\x62\x32\x67\x35\x6b\x61\x5e\x6f\x62\x77\x32\x63\x73\x7f\x24\x3e\x0f\x26\x21\x22\x23\x74\x77\x6f\x6f\x76\x2b\x23\x5c\x69\x74\x22\x62\x76\x60\x26\x68\x6c\x22\x24\x3f\x2f\x26\x2b\x09\x61\x69\x75\x64\x38\x09\x24\x25\x26\x21\x72\x71\x6d\x6b\x72\x29\x25\x54\x76\x6a\x68\x66\x22\x73\x65\x76\x75\x76\x6d\x71\x60\x25\x3c\x29\x25\x2a\x0e"

key = "\x01\x02\x03\x04\x05\x06"

print("".join([chr(ord(c)^ord(key[i%len(key)])) for i,c in enumerate(code)]))
```

[![image.png](https://i.postimg.cc/HnSBJwb3/image.png)](https://postimg.cc/vxVWk6q6)

## Flag : 

```
DEFENSYS{x0r_enc0d1ng_mas7er}
```
