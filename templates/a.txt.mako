Name: ${name}
Age: ${age}
Hobby: ${hobby}

## 调用函数
${greet(name, age, hobby)}
## 定义函数
<%!
import datetime
def greet(name, age, hobby):
    return f"hi, i'm {name}, i'm {27} years old, i like {hobby}.   \n{datetime.datetime.now()}"
%>
