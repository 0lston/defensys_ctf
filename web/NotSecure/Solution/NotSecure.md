
### Description
Try to be admin if you can


### Writeup


in this challenge we are not provided with the source code
when visiting the / route we got a login panel
entering `admin` as a username will return username too short
![[web/NotSecure/Solution/image1.png]]

so trying a longer username will redirect us to `/flag`

![[web/NotSecure/Solution/image2.png]]

by checking the devtools we will see a token cookie that looks like a jwt

![[web/NotSecure/Solution/image3.png]]

and indeed its a jwt token 
![[web/NotSecure/Solution/image4.png]]
(image from http://jwt.io)

we see that the signing algorithm is HS256, so we can try to bruteforce it using `jhon the ripper`

* save the jwt token to a file `jwt.txt` : `echo "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ1c2VybmFtZSI6ImFhYWFhYWFhYWFhYWFhYWFhYWFhYWFhIiwicGFzc3dvcmQiOiJhYWFhIiwiZXhwIjoxNzA5MDM0NDY0fQ.JlUNcUs1cTtxN-224Sm8wUk8N31eJCFxyET0msgf0wg" > jwt.txt`
* run john with format as HMAC-SHA256 and with the `rockyou.txt`  (use your own rockyou path) wordlist: `john --format=HMAC-SHA256 --wordlist=/usr/opt/SecLists/Passwords/Leaked-Databases/rockyou.txt jwt.txt`
![[Pasted image 20240227123534.png]]
* this HS256 secret is `wiwikiki`
* now visit http://jwt.io and modify the `username` to `admin` and use `wiwikiki` as a secret then take the generated token and put it in the cookies in devtools
* now visit `/flag` and take the flag

#### The flag
`DEFENSYS{ins3cUr3__s3cr3t5_4r3_Dangerous_31338}`
