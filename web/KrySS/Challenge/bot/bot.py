from selenium import webdriver
from selenium.webdriver.chrome.options import Options
from selenium.webdriver.support.ui import WebDriverWait
from selenium.webdriver.chrome.service import Service
import time

HOST_NAME = "http://127.0.0.1:8080"


def visit_report(url):
    chrome_options = Options()
    chrome_options.add_argument("--headless")
    chrome_options.add_argument('--no-sandbox')
    chrome_options.add_argument('--disable-dev-shm-usage')
    chrome_options.add_argument('--disable-infobars')
    chrome_options.add_argument('--disable-background-networking')
    chrome_options.add_argument('--disable-default-apps')
    chrome_options.add_argument('--disable-extensions')
    chrome_options.add_argument('--disable-gpu')
    chrome_options.add_argument('--disable-sync')
    chrome_options.add_argument('--disable-translate')
    chrome_options.add_argument('--hide-scrollbars')
    chrome_options.add_argument('--metrics-recording-only')
    chrome_options.add_argument('--mute-audio')
    chrome_options.add_argument('--no-first-run')
    chrome_options.add_argument('--dns-prefetch-disable')
    chrome_options.add_argument('--safebrowsing-disable-auto-update')
    chrome_options.add_argument('--media-cache-size=1')
    chrome_options.add_argument('--disk-cache-size=1')
    chrome_prefs = {}
    chrome_options.experimental_options["prefs"] = chrome_prefs
    chrome_prefs["profile.default_content_settings"] = {"images": 2}

    service = Service(
        executable_path=r'/usr/local/bin/chromedriver-linux64/chromedriver', log_output='/tmp/chromedriver.log')

    browser = webdriver.Chrome(service=service, options=chrome_options)

    browser.get(HOST_NAME)

    browser.add_cookie({
        'name': 'flag',
        'value': 'DEFENSYS{N3x7_T1m3_U5e_a_s3cuR3_PRNG_31337123}',
        'Domain': HOST_NAME
    })
    try:
        browser.get(url)

        time.sleep(10)
    except (TimeoutException, WebDriverException):
        return "an erro has accured"

    browser.quit()
    return "sucess"
