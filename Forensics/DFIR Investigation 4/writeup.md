## Searching for the malicious trojan name : 

let's search in the log files for defender to get the log file responsible for logging windows defender events

[![image.png](https://i.postimg.cc/fRC15bMh/image.png)](https://postimg.cc/4YK8xsK8)

as always we will start by investigating the operational logs, double click on the log file and it'll be opened by event viewer application


let's search for windows defender event ids and we have the official microsoft documentation

[![image.png](https://i.postimg.cc/TPmgfK1z/image.png)](https://postimg.cc/Y4rhxq1R)

reading through event ids and each one and his role we stumble upon interesting event ids which are 1006 and 1116 

[![image.png](https://i.postimg.cc/XYhNxxjW/image.png)](https://postimg.cc/w1XdjXR4)

[![image.png](https://i.postimg.cc/2Sx3wnq8/image.png)](https://postimg.cc/Wdh2pF6Q)

filtering base on the `event id 1006` doesn't yield any results so we will pass to the next one.

let's filter based on the `event id 1116`

[![image.png](https://i.postimg.cc/tTshwBPz/image.png)](https://postimg.cc/Q9r9WkfB)

and boom we have the path to the malicious executable

**name of the executable => hack_persist.exe**

## Flag : 

```
DEFENSYS{hack_persist.exe}
```
