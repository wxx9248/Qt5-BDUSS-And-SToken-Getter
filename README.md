
# Qt5-BDUSS-And-SToken-Getter

自动获取百度BDUSS值和STOKEN值，用于经验值迁移系统

## 系统要求
* 推荐使用 Windows 10，或者macOS 10.15+
* 最低系统要求：Windows 7 SP1，或者macOS 10.13
* **不支持 Windows XP 和 Vista**
 
## 使用方法
* 前往 [Release页面](https://github.com/wxx9248/Qt5-BDUSS-And-SToken-Getter/releases) 下载最新版本
	* `x86`结尾的适用于32位系统
	* `amd64`结尾的适用于64位系统
* 解压zip文件，点击其中的`Getter.exe`，或者macOS版本为`Getter.app`
* 如果满足系统要求，程序主界面会打开，如下图：

![主界面](https://raw.githubusercontent.com/wxx9248/Qt5-BDUSS-And-SToken-Getter/master/img/00.png)
* 在左边按照正常的登录流程登录百度贴吧，右边就会显示BDUSS和SToken的值
* 点击右边`Cookie抓取结果`栏中对应项目的`复制值`按钮，复制对应的值，如下图：

![Cookie抓取结果](https://raw.githubusercontent.com/wxx9248/Qt5-BDUSS-And-SToken-Getter/master/img/01.png)

## FAQ
1. BDUSS和SToken不能使用

	 点击右边的`清除Cookies`，再点击`刷新`，重新登录获取BDUSS和SToken。
	 
2. 程序无法打开，提示`无法找到入口点`

	请不要删除提取出来的**任何文件**，那些都是运行此程序所必要的支持库。
	
3. 如果有其他问题，请在 [issues页面](https://github.com/wxx9248/Qt5-BDUSS-And-SToken-Getter/issues) 反馈问题，反馈时请提供**你的操作系统版本**，并**详细描述程序的错误**，并附上**屏幕截图**（不要用手机拍屏幕！）；如果提供的信息过于少，将不提供技术支持。

## 附录
* [经验转移系统](https://exptransfer.wxx9248.tk:8443/)
* [驯龙高手吧论坛](https://www.httydbar.com/)
