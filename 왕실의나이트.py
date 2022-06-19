coor=input()
row=eval(coor[1])
col=ord(coor[0])
drow=[2, 2, 1, -1, -2, -2, -1, 1]
dcol=[-1, 1, 2, 2, 1, -1, -2, -2]
move=['nl', 'nr', 'el', 'er', 'sl', 'sr', 'wl', 'wr']

count=0

for i in range(len(move)):
  nrow=row+drow[i]
  ncol=col+dcol[i]

  if(nrow<1 or nrow >8 or ncol<97 or ncol>104):
    continue
  else:
    count+=1

print(count)
