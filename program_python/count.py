# -*- coding: utf-8 -*-

def count(s):
    count_a=count_z=count_o=count_A=0
    for i in s:
        if (ord(i)>=97 and ord(i)<=122) :
            count_a=count_a+1
        elif (ord(i)>=65 and ord(i)<=90):
            count_A=count_A+1
        elif ord(i)>=48 and ord(i)<=57:
            count_z=count_z+1
        else:
            count_o=count_o+1
    tup1=(count_a,count_A,count_z,count_o)
    print ("小写英文字母个数："  ,tup1[0] )
    print ("大写英文字母个数："  ,tup1[1] )
    print ("数字个数："  ,tup1[2] )
    print ("其他字符个数："  ,tup1[3] )
 
 
if __name__=="__main__":
    s=input("请输入一串字符：")
    count(s)
