# 简易扑克牌类的设计与实现

## Description

设计并实现一个扑克牌类`Card`，表示一幅纸牌，要求：

1. 用数组表示除大小王外的一幅纸牌共52张，***每张纸牌有花色和点数***，花色分为4种，
分别对应黑桃(`Spade: S`)、红桃(`Heart: H`)、方片(`Diamond: D`)和梅花(`Club:C`)，
如黑桃`A`简记为`SA`，梅花`6`简记为`C6`；

2. <mark>读入随机洗好的52张牌</mark>；

3. 支持从洗好的牌中按位置抽取某一张牌的操作`pick()`；

4. 支持计算每张纸牌分数的操作`getScore()`，其中
每张牌的分数定义如下：`“J”、“Q”、“K”、“A”`分别对应
分值10、10、10、11，其它`“2~10”`分值对应其字面点数。  

编写测试程序，模拟***两个玩家[^player] **<u>交错</u>抽取5张牌，
显示双方的花色和点数，并根据总分值判断输赢。

[^player]: 玩家可使用class player定义，也可以直接使用一个vector表示
***

## Input

随机洗好的52张牌花色及点数，玩家1抽取牌的序号，玩家2抽取牌的序号。


## Output

显示双方5张牌的花色、点数和总分值，两个玩家的输赢结果，
> - 如果玩家1赢得比赛，输出“Player 1 wins!”，
> - 如果玩家2赢得比赛，输出“Player 2 wins!”，
> - 如果平局，输出“Draw!”。



***

## Sample 示例

### Sample Input 1 

H6 H2 D9 C8 D2 SK C2 DJ S9 CJ H8 S6 C3 D8 S5 S7 D10 H9 DK HQ H10 D4 CQ SJ C4 H4 D3 H5 S10 DQ C10 S4 C9 HK DA S2 S8 C5 CA CK C6 HA D7 SQ H3 H7 HJ D5 S3 D6 SA C7
0 3 5 9 16
7 10 18 20 40
### Sample Output 1

Player 1 got: H6 C8 SK CJ D10
Player 1 points: 44
Player 2 got: DJ H8 DK H10 C6
Player 2 points: 44
Draw!

***

### Sample Input 2 

CQ S10 S7 S5 H2 D10 H3 C2 S6 S9 SK C5 H10 H8 S8 D3 D9 C9 HA SA S3 C10 CJ H7 C4 DJ HK S4 H6 DQ H9 DA D6 HQ D7 DK CA SJ C6 D8 HJ CK D4 H4 SQ S2 C3 C7 D2 C8 H5 D5
0 2 4 6 8
1 3 5 7 9
### Sample Output 2

Player 1 got: CQ S7 H2 H3 S6
Player 1 points: 28
Player 2 got: S10 S5 D10 C2 S9
Player 2 points: 36
Player 2 wins!

***

### Sample Input 3 

S5 S4 D3 CQ DJ HJ H7 H4 CK C2 HA D8 C10 DK S9 SJ DA HK CA C6 S10 H6 C5 C7 S6 C8 D6 C4 SK D10 S8 S7 D9 H8 H10 S3 DQ H9 SQ H5 C9 C3 H3 D2 CJ SA H2 D5 D7 D4 S2 HQ
0 2 4 6 8
1 3 5 7 9
### Sample Output 3

Player 1 got: S5 D3 DJ H7 CK
Player 1 points: 35
Player 2 got: S4 CQ HJ H4 C2
Player 2 points: 30
Player 1 wins! 

***
