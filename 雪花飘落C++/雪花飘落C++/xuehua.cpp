
#include <graphics.h>

#define MAX_STAR 500			// 雪花数量上限
#define SCREEN_WIDTH 640		// 屏幕宽度
#define SCREEN_HEIGHT 480		// 屏幕高度
#define MAX_STEP 3				// 雪花每次移动最高步长
#define MAX_RADIUS 3			// 雪花最大半径
#define IMGNAME _T("img.jpg")	// 图片名字

using namespace std;

// 图片转数组（这个有很大优化空间的，需要识别彩色照片可以看这）
int imgList[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

// 雪花状态
enum STATUS
{
	STOP = 0,	// 不动
	UP,			// 向上
	DOWN,		// 向下
	LEFT,		// 向左
	RIGHT,		// 向右
	RANDOM,		// 随机
	ALL_STATUS	// 记录状态总数
};
struct STAR
{
	int x;				// 雪花的 x 坐标
	int y;				// 雪花的 y 坐标
	enum STATUS stat;	// 雪花状态
	unsigned radius;	// 雪花的半径
	int step;			// 雪花每次移动的步长
	int color;			// 雪花的颜色
};
struct SqList
{
	struct STAR* elems; // 顺序表的基地址
	int length;			// 顺序表的长度
	int size;			// 顺序表的空间
};

// 接口声明
bool initList(SqList& L);
bool listAppend(SqList& L, struct STAR e);
bool listDelete(SqList& L, int i);
void destroyList(SqList& L);

// 初始化顺序表
bool initList(SqList& L) {
	L.elems = new struct STAR[MAX_STAR]; // 为顺序表分配存储空间
	if (!L.elems) return false; // 如果分配存储空间失败，则返回 false
	L.length = 0; // 初始化表长为0
	L.size = MAX_STAR; // 初始化表空间大小为MAX_STAR
	return true; // 返回 true 表示初始化成功
}

// 追加元素到顺序表末尾
bool listAppend(SqList& L, struct STAR e) {
	if (L.length == L.size) return false; // 如果顺序表已满，则返回 false
	L.elems[L.length] = e; // 将元素 e 添加到表的末尾
	L.length++; // 表长加1
	return true; // 返回 true 表示添加成功
}

// 删除顺序表中指定位置的元素
bool listDelete(SqList& L, int i) {
	if (i < 0 || i >= L.length) return false; // 如果下标 i 不合法，则返回 false
	for (int j = i; j < L.length - 1; j++) { // 将 i 及其后面的元素往前移动一位
		L.elems[j] = L.elems[j + 1];
	}
	L.length--; // 表长减1
	return true; // 返回 true 表示删除成功
}

// 销毁顺序表
void destroyList(SqList& L) {
	delete[] L.elems; // 释放顺序表的存储空间
	L.length = 0; // 将表长和表空间置为0
	L.size = 0;
	L.elems = NULL; // 将指针 elems 设为 null
}
/************************************
* 功能：移动雪花，并在指定区域留下雪痕
* 输入参数：
* L - 雪花对象
* i - 雪花在全局数组中的下标
* 返回值：无
************************************/
// 移动雪花
void MoveStar(SqList& L, int i) {
	// 根据雪花当前的状态进行移动
	if (L.elems[i].stat == DOWN) { // 向下飘动
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // 如果当前位置是白色，则继续向下移动
			L.elems[i].y += L.elems[i].step; // 往下移动一个步长
			L.elems[i].x -= 2; // 同时往左移动2个像素，使雪花产生飘动效果
		}
	}
	else if (L.elems[i].stat == UP) { // 向上飘动
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // 如果当前位置是白色，则继续向上移动
			L.elems[i].y -= L.elems[i].step; // 往上移动一个步长
			L.elems[i].x -= 2; // 同时往左移动2个像素，使雪花产生飘动效果
		}
	}
	else if (L.elems[i].stat == LEFT) { // 向左飘动
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // 如果当前位置是白色，则继续向左移动
			L.elems[i].x -= L.elems[i].step; // 往左移动一个步长
		}
	}
	else if (L.elems[i].stat == RIGHT) { // 向右飘动
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // 如果当前位置是白色，则继续向右移动
			L.elems[i].x += L.elems[i].step; // 往右移动一个步长
		}
	}

	// 如果雪花状态为停止，则直接返回
	if (L.elems[i].stat == STOP) return;

	// 擦除当前位置的雪花
	// 设置填充颜色为黑色
	setfillcolor(BLACK); 
	// 在当前位置绘制一个黑色的实心圆，擦除雪花
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius); 
	// 根据雪花当前的状态进行移动，并在新位置绘制雪花
	if (L.elems[i].stat == DOWN) { // 向下飘动
		L.elems[i].y += L.elems[i].step; // 往下移动一个步长
		L.elems[i].x -= 2; // 同时往左移动2个像素，使雪花产生飘动效果
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH; // 如果雪花已经飘到屏幕左侧，则将其移到屏幕右侧
		if (L.elems[i].y > SCREEN_HEIGHT) L.elems[i].y = 0; // 如果雪花已经飘到屏幕下方，则将其移到屏幕顶部
		//if(L.elems[i].y>SCREEN_HEIGHT) listDelete(L, i);	// 这段代码可以让飘出屏幕外的雪花消亡
	}
	else if (L.elems[i].stat == UP) { // 向上飘动
		L.elems[i].y -= L.elems[i].step; // 往上移动一个步长
		L.elems[i].x -= 2; // 同时往左移动2个像素，使雪花产生飘动效果
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH; // 如果雪花已经飘到屏幕左侧，则将其移到屏幕右侧
		if (L.elems[i].y < 0) L.elems[i].y = SCREEN_HEIGHT; // 如果雪花已经飘到屏幕顶部，则将其移到屏幕下方
		//if(L.elems[i].y<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == LEFT) { // 向左飘动
		L.elems[i].x -= L.elems[i].step; // 往左移动一个步长
		if (L.elems[i].x > 0) L.elems[i].x = SCREEN_WIDTH; // 如果雪花已经飘到屏幕右侧，则将其移到屏幕左侧
		//if(L.elems[i].x<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == RIGHT) { // 向右飘动
		L.elems[i].x += L.elems[i].step; // 往右移动一个步长
		if (L.elems[i].x > SCREEN_HEIGHT) L.elems[i].x = 0; // 如果雪花已经飘到屏幕左侧，则将其移到屏幕右侧
		//if(L.elems[i].x>SCREEN_WIDTH) listDelete(L, i);
	}

	// 在新位置绘制雪花
	setfillcolor(L.elems[i].color); // 设置填充颜色为雪花的颜色
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius); // 在新位置绘制一个实心圆，表示雪花
}


/************************************
* 功能：初始化雪花
* 输入参数：
* i - 雪花在全局数组中的下标
* 返回值：无
************************************/
void initStar(struct STAR& _star)
{
	int rgb = 0;
	//rand() 得到随机数范围 0 - 32767 RAND_MAX
	_star.x = rand() % SCREEN_WIDTH;		// x 范围 0 - SCREEN_WIDTH
	_star.y = rand() % SCREEN_HEIGHT;		// y 范围 0 - SCREEN_HEIGHT
	//_star.stat = STATUS(rand() % 6);		// 雪花状态：随机
	_star.stat = DOWN;						// 雪花状态：向下
	_star.radius = 1 + rand() % MAX_RADIUS; // 半径控制 1 - MAX_RADIUS
	_star.step = rand() % MAX_STEP + 1;		// 步长 1 - MAX_STEP
	rgb = 255 * _star.step / MAX_STEP;		// RGB：0 - 255
	_star.color = RGB(rgb, rgb, rgb);
}


int main()
{
	bool quit = false; // 标记是否退出程序
	struct STAR star; // 定义一个雪花结构体
	SqList starList; // 定义一个顺序表，用于保存所有雪花的状态

	// 初始化屏幕
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	// 初始化图片
	IMAGE img;
	loadimage(&img, IMGNAME); // 加载指定名称的图片
	SetWorkingImage(&img); // 将图片设置为绘制设备
	COLORREF color; // 定义一个COLORREF类型变量，用于存储像素颜色
	BYTE r, b, g; // 定义三个BYTE类型变量，用于存储像素的RGB值

	// 遍历图片的所有像素，记录需要留下“雪痕”的位置
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			color = getpixel(x, y); // 获取当前像素点的颜色
			r = GetRValue(color); // 获取像素点的红色分量
			b = GetBValue(color); // 获取像素点的蓝色分量
			g = GetGValue(color); // 获取像素点的绿色分量
			if (r < 200 && b < 200 && g < 200) // 判断当前像素点是否需要留下“雪痕”
			{
				imgList[y][x] = 1; // 将当前像素点标记为需要留下“雪痕”的位置
			}
		}
	}

	SetWorkingImage(); // 将绘制设备设置回默认
	cleardevice(); // 清空屏幕

	// 初始化保存雪花状态的顺序表
	initList(starList);

	// 随机生成 MAX_STAR 个雪花，并将其状态保存到顺序表中
	for (int i = 0; i < MAX_STAR; i++)
	{
		initStar(star); // 初始化一个雪花状态
		listAppend(starList, star); // 将该雪花状态保存到顺序表中
	}

	// 在屏幕上绘制所有雪花
	for (int i = 0; i < starList.length; i++)
	{
		setfillcolor(starList.elems[i].color); // 设置当前雪花的填充颜色
		solidcircle(starList.elems[i].x, starList.elems[i].y,
			starList.elems[i].radius); // 在屏幕上绘制当前雪花
	}

	// 让所有雪花开始飘动
	while (quit == false)
	{
		for (int i = 0; i < starList.length; i++)
		{
			MoveStar(starList, i); // 移动当前雪花
		}

		if (starList.length == 0) // 若设置雪花离开屏幕后消亡，则会触发此退出
		{
			quit = true;
		}

		Sleep(50); // 等待一段时间，使雪花飘动效果更加自然
	}

	system("pause"); // 暂停程序，等待用户按下任意键
	closegraph(); // 关闭图形界面
	return 0;
}