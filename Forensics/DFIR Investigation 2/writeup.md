## Find User Created :

let's search in the internet for the event responsible for logging the creation of a new user

[![image.png](https://i.postimg.cc/VNFjp8Xc/image.png)](https://postimg.cc/cKrgtPDD)

so let's search for the `event id 4720` in the `security.evtx` log file since it contains most of the system security events. double click on security.evtx and it'll be opened by `event viewer` and then we will filter by the event id 4720

[![image.png](https://i.postimg.cc/SRn1msG9/image.png)](https://postimg.cc/K3yDNmwc)

**user created => hacker**

remember the SID for the user hacker because in the next event responsible for adding a member to a group will contain only the SID of the member so we will search for the user hacker based on his unique SID
`S-1-5-21-1166243229-1269328664-1114898641-1001`
## Find the localgroup assigned to the user hacker : 

again searching in the internet for the event id responsible for logging this information we find the `event id 4732`

[![image.png](https://i.postimg.cc/3NkJXX3c/image.png)](https://postimg.cc/8fVSDrJR)

again filtering by this event id in the `security.evtx` log file

we can see that the Member added to administrators group has an SID typical to the user hacker so this ensures that the user hacker was added to the `administrators` group

Note that each user has a unique SID and each SID contain 5 parts the last part is called RID (Relative id) which is assigned uniquely to each user in the system.

[![image.png](https://i.postimg.cc/9ftQBXZy/image.png)](https://postimg.cc/qtqrJTm7)

**hacker added to => administrators**
## Flag : 

```
DEFENSYS{hacker_administrators}
```
