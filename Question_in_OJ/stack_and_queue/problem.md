# 单链表类的继承与派生

## 📘 题目描述

设计单链表类，并基于该单链表类实现栈类和队列类。

---

## 🔹（1）学生信息类

设计类 `StudentRecord`，要求：

- 公有数据成员：
  - `string stuName`
  - `int stuNo`
- 公有成员函数：
  - `void Print()`  
    输出格式为：
    ```
    stuName stuNo
    ```

---

## 🔹（2）单链表类

基于 STL 中的 `<list>`，设计学生链表类 `LinkedList`：

- 私有数据成员：
  - `list<StudentRecord> lst`

- 实现以下功能（公有成员函数）：
  - 头插入
  - 头删除
  - 尾插入
  - 尾删除
  - 遍历输出所有学生信息

---

## 🔹（3）栈类

由 `LinkedList` 派生 `LinkedStack`，实现：

- `void Push(const StudentRecord &record)`  
  → 压栈

- `bool Pop(StudentRecord &record)`  
  → 出栈  
  - 成功返回 `true`
  - 栈空返回 `false`

---

## 🔹（4）队列类

由 `LinkedList` 派生 `LinkedQueue`，实现：

- `void EnQueue(const StudentRecord &record)`  
  → 入队

- `bool DeQueue(StudentRecord &record)`  
  → 出队  
  - 成功返回 `true`
  - 队空返回 `false`

---

## 🔹（5）主函数要求

在 `main` 函数中：

- 定义：
  - 一个 `LinkedQueue` 对象 `queue`
  - 一个 `LinkedStack` 对象 `stack`

- 根据输入执行操作：

| 输入指令 | 操作 |
|----------|------|
| `Push` | 入栈 |
| `EnQueue` | 入队 |
| `Pop` | 出栈 |
| `DeQueue` | 出队 |
| `Exit` | 退出程序并输出结果 |
| 其它字符串 | 输出 `"Input error!"` |

---

## 🔹（6）输入规则

- 输入操作名
- 若为 `Push` 或 `EnQueue`：
  - 接着输入：学生姓名 + 学号

---

## 🔹（7）输出规则

### 出栈 / 出队：

- 若成功：
  ***
  输出元素
  ***
-  若失败：
-     栈空：
  ```
  Stack is empty!
  ```
-    队空：
  ```
  Queue is empty!
  ```

---

### Exit 时输出：

- 输出栈中剩余元素（按出栈顺序，即后进先出）
- 输出队列中剩余元素（按出队顺序，即先进先出）

---

## 🔹（8）样例输入
Push
ZhangSan 200905
Push
LiSi 200906
Push
WangWu 200908
EnQueue
LiKui 200915
EnQueue
ZhenShiyin 200916
EnQueue
ZhanGuang 200917
EnQueue
ChengRixing 200918
EnQueue
HuLai 200919
Dequeue
Pop
exit
Exit

---

## 🔹（9）样例输出
Input error!
WangWu 200908
Input error!
LiSi 200906
ZhangSan 200905
LiKui 200915
ZhenShiyin 200916
ZhanGuang 200917
ChengRixing 200918
HuLai 200919