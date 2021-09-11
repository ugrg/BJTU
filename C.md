#子序列
乔治最喜欢玩的游戏是数字的无穷序列，他把所有的自然数按升序排列，于是得到一个无穷序列，其开始部分是`1234567891011121314...`。将该序列记作`S`，则有`S[1]=1`,`S[2]=2`,`...`,`S[10]=1`,`S[11]=0`,`...`, 以此类推。

对于有限的`n`个自然数组成的`S`，如`n`为`10`的话，`S`为`12345678910`。乔治现有一个数字系列`A`，他想知道序列`A`在序列`S`中出现的次数，你能帮助他解决这个问题吗？

## 输入数据:
输入中只有一行，包括`n(1≤n≤104)`和`A`两部分，两者之间以单个空格分隔。其中`n`为形成序列`S`的自然数个数；`A`为待查的数字序列，其长度不超过`200`位，中间没有空白。

## 输出数据
在单独的行中输出序列A在序列S中出现的次数。

###样例输入:
```shell script
14 12
```
###样例输出:
```shell script
2
```
## 说明
若`A`为`111`，则对于`S`中子序列为`1111`的部分，`A`出现的次数为`2`。