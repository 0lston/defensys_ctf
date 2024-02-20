## Finding the malicious service created by the attacker : 

as always let's search for the event id in the internet

[![image.png](https://i.postimg.cc/rz2yMwHp/image.png)](https://postimg.cc/H831tddG)

let's click on the first link for more informations regarding the event id 7045 which is responsible for logging service creation infos

[![image.png](https://i.postimg.cc/PrBKnpMj/image.png)](https://postimg.cc/D8P1qzDj)

here we have the category is system so let's search for the `event id 7045` in the `system.evtx` log file, double click on this file and it'll be opened by the event viewer application

[![image.png](https://i.postimg.cc/NGdqwcF4/image.png)](https://postimg.cc/YjLy1T1G)

**servicename => MalService**
## Flag : 

servicename should be lowercase based on the challenge description instructions so MalService => malservice

```
DEFENSYS{malservice}
```
