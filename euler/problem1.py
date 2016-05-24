natural = 1
soma = 0
maxi = 1000
multiple_3 = 0
multiple_5 = 0
multiple_15 = 0

while (multiple_3<maxi or multiple_5<maxi or multiple_15<maxi):  
  if(multiple_3<maxi):
    soma = soma + multiple_3
  if(multiple_5<maxi):
    soma = soma + multiple_5 
  multiple_3 = natural*3
  multiple_5 = natural*5
  multiple_15 = (natural*15) + multiple_15
  natural+=1
  
natural = 1
while (multiple_15<maxi):  
  multiple_15 = (natural*15) + multiple_15
  natural+=1
  

soma = soma - multiple_15
print(soma)
  
