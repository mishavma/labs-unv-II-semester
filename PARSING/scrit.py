import requests
from bs4 import BeautifulSoup as sp

SITE_NAME = "https://www.gpntb.ru/win/dewey/ddc-sum01.html"
SITE = "https://www.gpntb.ru/win/dewey/"
FILE = "data.txt"

def get_response(url):
    return requests.get(url, verify=False)

def get_html(url):
    content = url.content
    soup = sp(content, 'html.parser')
    return soup


response = get_response(SITE_NAME)
file = open(FILE, 'a', encoding='UTF8')

if response.status_code == 200:
    soup = get_html(response)    

    ddc_sum = soup.find("pre").find_all("a")
    
    id_ = 1
    for i in ddc_sum:
        url_ddc = SITE + i.get('href')
        response_url = get_response(url_ddc)

        if response_url.status_code == 200:
            print(f"[{id_}] [{url_ddc}]: 200")

            soup_ddc = get_html(response_url)
            ddc_urls = soup_ddc.find("pre").find_all("a")
            id_ur = 1

            for j in ddc_urls:
                next_url_ddc = SITE + j.get('href')
                response_3 = get_response(next_url_ddc)

                if response_3.status_code == 200:
                    print(f"[{id_}] [{url_ddc}] [{next_url_ddc}]: 200")

                    soup_3 = get_html(response_3)
                    text_info = soup_3.find("pre").text
                    
                    file.write(text_info)
                else:
                    print(f"[{id_}] [{url_ddc}] [{next_url_ddc}]: {response_3.status_code}")

            print('\n----\n')




        else:
            print(f"[{id_}] [{url_ddc}]: bad request | {response_url.status_code}")

        id_ += 1

else:
    print(f"[E] - bad request: {response.status_code}")



# https://www.gpntb.ru/win/dewey/ddc-sum01.html
