# XwayOS V3.0.0

## XwayOS Studio

模型：

* 新增基于AUTOSAR的新模型

前端：

* 前端支持远程调试&本地调试
* 更新 EM CM 相关模型，表单页面更新了对新模型的支持
  * 增加了如下模型类型
  * EXECUTABLE
  * EXECUTION-MAPPING
  * SOFTWARE-CLUSTER
  * MODE-DECLARATION-GROUP
  * FUNCTION-GROUP
  * STARTUP-CONFIG
  * SERVICE-INTERFACE
  * DDS-SERVICE-INSTANCE
  * DDS-SERVICE-INTERFACE-DEPLOYMENT
  * PROCESS-PORT-MAPPING
  * 删除了如下模型类型
  * DATA-SERVICE-INTERFACE
  * RPC-SERVICE-INTERFACE

代码引擎：

* EM模型校验
  * 错误详细信息打印
  * 错误路径点击跳转
* 支持RTF代码生成
  * EXECUTABLE入口程序生成
  * SW-COMPONENT runtime运行时代码生成
  * SW-COMPONENT用户示例代码生成
* 支持基于服务的通信
  * 服务接口代码
  * CM配置清单生成
  * rosmsg代码生成
* 执行管理
  * 执行清单生成
  * 编排清单生成
  * 机器清单生成
* 日志
  * 日志清单生成

## ACore

**通信**

* 兼容AUTOSAR AP 22-11标准
* 支持DDS绑定
* 支持Event

**执行管理**

* 进程生命周期管理（启动，终止）
* 功能组管理

**日志**

* 支持日志kconsole、kfile、kremote三种模式，即日志终端打印，落盘，网络传输
* 支持日志文件大小限制

**基础库**

* xos::osi:操作系统接口
* xos::thread：线程库
* xos::e2e：端到端保护
* xos::crc：冗余校验
* xos::xjson：json解析库
* xos::charconv：字符转换库
* xos::backtrace：异常退出堆栈打印
* xos::sheduler：runnable调度库
* xos::iostream：流处理

# XwayOS V3.1.0

ACore
-----

通信:
1.支持datasharing方式;
2.修复异常问题：偶发无法无法订阅，退出崩溃等;
3.代码、注释等优化;
4.去除对socal的依赖
5.评审后文档更新
其他:
1.删除暂时未用到的模块

工具链
------

1.支持CM模型校验;
2.模型校验支持提醒未被使用的元素;
3.update CM API and config;
4.优化代码生成速度，支持使用-j参数指定并发数；并发后性能最高有10倍提升;
5.多event时间处理;
7.支持用户指定以节点为单位的用户代码路径，如Camera_XWAY_USER_CODE_PATH;
8.在顶层cmake中增加代码引擎版本信息

## 前端

1.模型支持多层级元素引用关系展示、操作提醒和保存时自动更新引用关系
2.模型支持多层级元素导航
