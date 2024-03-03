opening the binary in ida or ghidra we find that our input is entered as an argument to a function called check_password that checks every character of the input enetered by the user

here is the function in ida pro
```
_BOOL8 __fastcall check_password(__int64 a1)
{
  if ( (unsigned int)strlen((const char *)a1) != 25 )
    return 0;
  if ( *(_BYTE *)a1 != 68
    || *(_BYTE *)(a1 + 5) != 83
    || *(_BYTE *)(a1 + 10) != 51
    || *(_BYTE *)(a1 + 15) != 110
    || *(_BYTE *)(a1 + 20) != 99 )
  {
    return 0;
  }
  if ( *(_BYTE *)(a1 + 1) != 69
    || *(_BYTE *)(a1 + 6) != 89
    || *(_BYTE *)(a1 + 11) != 118
    || *(_BYTE *)(a1 + 16) != 95
    || *(_BYTE *)(a1 + 21) != 48 )
  {
    return 0;
  }
  if ( *(_BYTE *)(a1 + 2) != 70
    || *(_BYTE *)(a1 + 7) != 83
    || *(_BYTE *)(a1 + 12) != 95
    || *(_BYTE *)(a1 + 17) != 98
    || *(_BYTE *)(a1 + 22) != 48 )
  {
    return 0;
  }
  if ( *(_BYTE *)(a1 + 3) == 69
    && *(_BYTE *)(a1 + 8) == 123
    && *(_BYTE *)(a1 + 13) == 99
    && *(_BYTE *)(a1 + 18) == 51
    && *(_BYTE *)(a1 + 23) == 108 )
  {
    return *(_BYTE *)(a1 + 4) == 78
        && *(_BYTE *)(a1 + 9) == 114
        && *(_BYTE *)(a1 + 14) == 52
        && *(_BYTE *)(a1 + 19) == 95
        && *(_BYTE *)(a1 + 24) == 125;
  }
  return 0;
}
```

we can see that it checks every character and compares it with an ascii character

let's use a python script to convert the ascii characters and find the string that our input is compared against

```bash
azer@DESKTOP-OQ42TBR MINGW64 ~/Desktop
$ cat ascii.py
ascii_numbers = [68, 69, 70, 69, 78, 83, 89, 83, 123, 114, 51, 118, 95, 99, 52, 110, 95, 98, 51, 95, 99, 48, 48, 108, 125]

# Convert ASCII numbers to letters
password = ''.join(chr(num) for num in ascii_numbers)

print(password)

azer@DESKTOP-OQ42TBR MINGW64 ~/Desktop
$ python ascii.py
DEFENSYS{r3v_c4n_b3_c00l}
```

## Flag : 

```
DEFENSYS{r3v_c4n_b3_c00l}
```
