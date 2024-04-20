from flask import Flask, request, jsonify
import re

app = Flask(__name__)


@app.route('/')
def index() -> str:
    return "<h1>PEW PEW post to /pew</hjson>"


@app.route('/pew', methods=['POST'])
def execute_code() -> jsonify:
    user_code = request.form['pew']
    if re.match(".*[\x20-\x7E]+.*", user_code):
        return jsonify({"output": "PEW PEW you can't use chars"}), 403

    if len(user_code) >= 77:
        return jsonify({"output": "PEW PEW too long"}), 403

    try:
        result = eval(user_code)
    except Exception as e:
        result = str(e)

    return jsonify({"output": result}), 200


def main():
    app.run(host="0.0.0.0", port=1337, debug=False)


if __name__ == "__main__":
    main()
