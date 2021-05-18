# 单线雷达带反光板定位算法

本算法使用倍加福2000雷达加上反光板作为定位的硬件.

## 反光板匹配定位

### 分割反光板点云

使用固定阈值分割分离反光板点云，并根据反光板的远近粗略估计点云数量而过滤错误反光板点云，公式如下:

<img src="https://rawgit.com/e	git@gitee.com:uanheng/posing/master/svgs/9da21ff59577a923dac7a9ca025eb112.svg?invert_in_darkmode" align=middle width=129.67589745pt height=24.65753399999998pt/>

其中n为理论反光板点云数量，r为反光板半径，f为激光雷达角分辨率，l为反光板到激光雷达的距离.

### 获取反光板坐标

在获取到反光板的激光点云后，使用**三角函数法**计算反光板的圆心。

### 匹配反光板

使用三角形匹配法确定各反光板的序号，首先将地图中的所有反光板组成的三角形根据边长进行排序，在通过局部反光板形成的三角形进行匹配。

### 三边定位

假设激光雷达扫描到 n 个反光板(n≥3),则
<img src="https://rawgit.com/e	git@gitee.com:uanheng/posing/master/svgs/85b54654df6b5a546c2dec83061f90ea.svg?invert_in_darkmode" align=middle width=235.6102716pt height=82.08242790000003pt/>
用其中的前n − 1个方程减去第n个方程,可以得到
<img src="https://rawgit.com/e	git@gitee.com:uanheng/posing/master/svgs/d52d2eca35e6701c3637f49d6be96e1d.svg?invert_in_darkmode" align=middle width=65.88059444999999pt height=22.831056599999986pt/>
其中 
<img src="https://rawgit.com/e	git@gitee.com:uanheng/posing/master/svgs/d8cb1ccf2aef134eba8db95179a9fdc6.svg?invert_in_darkmode" align=middle width=281.0655804pt height=77.26096289999998pt/>
<img src="https://rawgit.com/e	git@gitee.com:uanheng/posing/master/svgs/abe2b54cee5210fa5103ac82d1372b35.svg?invert_in_darkmode" align=middle width=321.6932103pt height=77.48337299999997pt/>
使用最小二乘法得到全局坐标，并算出偏转角度，如下：
<img src="https://rawgit.com/e	git@gitee.com:uanheng/posing/master/svgs/6d895c5ada3acb4002dc1d8ba77a559c.svg?invert_in_darkmode" align=middle width=141.68326754999998pt height=27.6567522pt/>
<img src="https://rawgit.com/e	git@gitee.com:uanheng/posing/master/svgs/2761167880c3cb011d92d8780b5de11b.svg?invert_in_darkmode" align=middle width=222.79411439999993pt height=30.92230019999999pt/>