d = 256613 # AU
v = 3.3 # AU / year
lyear = 1977
print('Probe #   | Launch Year | Speed | Year of Arrival')
for i in range(13):
    v_new = v*(1.1**i)
    tof = d/v_new
    yearofarrival = round(lyear+100*i+tof) 
    print(f'Voyager {i+2} | {lyear+100*i} | {round(v_new,2)} | {yearofarrival}')

