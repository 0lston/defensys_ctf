```
ls /
```

[![image.png](https://i.postimg.cc/cCyWxw8h/image.png)](https://postimg.cc/ZBc2j9Hv)

now we have to read the flag.txt file

[![image.png](https://i.postimg.cc/rFq6f8GD/image.png)](https://postimg.cc/QVYntZyD)

most of the commands that enables you to read a file like tail head ...etc are blacklisted

so we have to look for obfuscated payloads to bypass the blacklisting. there is a huge github repository that contains payloads for all vulnerabilities that exist called payloadAllTheThings
searching for payloads to bypass blacklisted commands we find this link

https://github.com/swisskyrepo/PayloadsAllTheThings/tree/master/Command%20Injection#bypass-blacklisted-words

[![image.png](https://i.postimg.cc/sXfSnG2n/image.png)](https://postimg.cc/R38NhFKf)

so let's use one of those and let's check if we can read the flag.txt file.
and almost all of them work

![image](https://github.com/0lston/defensys_ctf/assets/97733918/f84b8591-cce8-44eb-97d2-f92376e37476)

## Flag : 
```
DEFENSYS{bl4ck_l1s7ing_15_n0t_g00d_4nyways}
```
