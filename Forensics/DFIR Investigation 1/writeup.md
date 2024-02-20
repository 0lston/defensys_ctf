## attacker ip and successfull logon time :

we are provided with windows event logs which provides information about hardware and software events occurring on a Windows operating system and each specific diffrent operation is given an event id.

searching in the internet for RDP Log Events we find the successful logon events 

https://shreenkhalabhattarai.medium.com/unraveling-rdp-events-understanding-remote-desktop-protocol-for-enhanced-security-78e6c1222bf

[![image.png](https://i.postimg.cc/1z2wrwXd/image.png)](https://postimg.cc/p9Qm29DQ)

so there is multiple log files that contains the rdp logon time but each file has a diffrent event id, let's start by the first one `Microsoft-Windows-TerminalServices-RemoteConnectionManager%4Operational.ectx` and the eventid 1149 is what we are looking

to search for this even id in this evtx file we will open it using windows builtin event viewer, just double click on the file on windows and it will be opened automatically by event viewer application.

[![image.png](https://i.postimg.cc/jdxwNZv5/image.png)](https://postimg.cc/z3QGYwsZ)

click on `Filter Current Log` on the right Action Panel, filter by the event id 1149 and click on ok

[![image.png](https://i.postimg.cc/CLr18YzP/image.png)](https://postimg.cc/yk9sqMhc)

[![image.png](https://i.postimg.cc/QtNGS9zp/image.png)](https://postimg.cc/064ByQPQ)
## number of failed attempts : 

again searching for unsuccessfull logon rdp events we will find 

[![image.png](https://i.postimg.cc/pLnFXyqY/image.png)](https://postimg.cc/68t3M6sy)

so let's open the security.evtx file using event viewer application and filter the log to search for the event id `4625`

[![image.png](https://i.postimg.cc/8k2FXT17/image.png)](https://postimg.cc/Z0LKCtvm)

we can see that we have multiple entries and each entry represents a failed attemp so what we have to do now is to calculate how many entries there and this number is the number of `failed attempts`

**attackerIp => 192.168.0.22**
**logontime => 19:35:49**
**number of failed attempts => 11**

## Flag : 

```
DEFENSYS{192.168.0.22_19:35:49_11}
```
