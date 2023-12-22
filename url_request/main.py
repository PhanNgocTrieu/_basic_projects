import requests as Request

url = 'https://www.youtube.com/watch?v=1urvWzyOsCA&list=RD1urvWzyOsCA&start_radio=1'
response = Request.get(url)

with open('file.pdf', 'wb') as f:
    f.write(response.content)
 