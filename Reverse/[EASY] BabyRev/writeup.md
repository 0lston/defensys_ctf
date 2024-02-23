let's reverse the code using ida pro, opening the main function we find an array of 45 in length in ascii.

[![image.png](https://i.postimg.cc/KcfGpCJM/image.png)](https://postimg.cc/DmW38pVv)

after this it gets the userInput and checks whether the userInput length is the same length as v10 which is 45 which means its checking if the userInput is the same length as the v6 array length, if the check is not correct it will say `Flag Wrong` if it's correct it will proceed by encrypting the userInput and compare it to the v6 array 

[![image.png](https://i.postimg.cc/zXSqH6RB/image.png)](https://postimg.cc/D8Z9tC6k)

now that we know that the correct size is 45 we will proceed by analyzing thi code

[![image.png](https://i.postimg.cc/9XD6jSBS/image.png)](https://postimg.cc/HjCZw6R4)

compares each index in the array of v6 with the encrypted value of the userInput `(so we can say that v6 is the encryptedFlag)`

let's analyze the encrypt function

[![image.png](https://i.postimg.cc/wjw2Mxqk/image.png)](https://postimg.cc/QFW1n3WB)

to make it clear this is equivalent to 

```c
(userInput[i] + 96) ^ index
```

so we have to enter an input when it enters the encrypt function it gives an output equal to v6 (encryptedFlag) array values

so we will extract the v6 array and reverse it to get the actual flag that will succed the check

```python
v6 = []
v6.append(164);
v6.append(164);
v6.append(164);
v6.append(166);
v6.append(170);
v6.append(182);
v6.append(191);
v6.append(180);
v6.append(211);
v6.append(221);
v6.append(221);
v6.append(155);
v6.append(179);
v6.append(157);
v6.append(222);
v6.append(156);
v6.append(194);
v6.append(131);
v6.append(198);
v6.append(130);
v6.append(132);
v6.append(219);
v6.append(197);
v6.append(168);
v6.append(137);
v6.append(140);
v6.append(165);
v6.append(200);
v6.append(141);
v6.append(208);
v6.append(206);
v6.append(211);
v6.append(229);
v6.append(158);
v6.append(246);
v6.append(179);
v6.append(155);
v6.append(247);
v6.append(181);
v6.append(241);
v6.append(187);
v6.append(251);
v6.append(249);
v6.append(184);
v6.append(241);

print(v6)

#[164, 164, 164, 166, 170, 182, 191, 180, 211, 221, 221, 155, 179, 157, 222, 156, 194, 131, 198, 130, 132, 219, 197, 168, 137, 140, 165, 200, 141, 208, 206, 211, 229, 158, 246, 179, 155, 247, 181, 241, 187, 251, 249, 184, 241]
```

reverse of this  `(userInput[i] + 96) ^ index` is `(encryptedFlag[i] ^ index) - 96`
## solve.py : 

```python
encrypted_flag = [164, 164, 164, 166, 170, 182, 191, 180, 211, 221, 221, 155, 179, 157, 222, 156, 194, 131, 198, 130, 132, 219, 197, 168, 137, 140, 165, 200, 141, 208, 206, 211, 229, 158, 246, 179, 155, 247, 181, 241, 187, 251, 249, 184, 241]

flag_ascii = []
for i in range(45):
    v8 = (encrypted_flag[i] ^ i) - 96
    flag_ascii.append(v8)

print(flag_ascii) #[68, 69, 70, 69, 78, 83, 89, 83, 123, 116, 119, 48, 95, 48, 112, 51, 114, 50, 116, 49, 48, 110, 115, 95, 49, 53, 95, 115, 49, 109, 112, 108, 101, 95, 116, 48, 95, 114, 51, 118, 51, 114, 115, 51, 125]
print('\n')
flag = ''.join(chr(value) for value in flag_ascii)

print(flag) #DEFENSYS{tw0_0p3r2t10ns_15_s1mple_t0_r3v3rs3}
```

## Flag : 

```
DEFENSYS{tw0_0p3r2t10ns_15_s1mple_t0_r3v3rs3}
```
