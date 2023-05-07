///////////////////////////////////////////////////
// 程序名称：图像处理——素描算法
// 编译环境：Mictosoft Visual Studio 2013, EasyX_20200315(beta)
// 作　　者：luoyh <2864292458@qq.com>
// 最后修改：2021-11-2
//

#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<cmath>

const double PI = acos(-1.0);
const double delta = 1.5;
const int pic_Dis = 3;
double P[pic_Dis][pic_Dis];
void GetP();						// 获取高斯滤波算子

class Algorithm
{
public:
	Algorithm(IMAGE* img, int width, int heigth);
	void Histogram();				// 类似直方图均衡化
	void Gray();					// 灰度处理
	void Film();					// 负片处理
	void Blur();					// 高斯模糊化处理
	void Sketch();					// 素描算法

private:
	IMAGE* pimg;
	int WIDTH;
	int HEIGHT;
};

Algorithm::Algorithm(IMAGE* img, int width, int height)
{
	pimg = img;
	WIDTH = width;
	HEIGHT = height;
};

void Algorithm::Film()
{
	DWORD* pMem = GetImageBuffer(pimg);
	for (int i = pimg->getwidth() * pimg->getheight() - 1; i >= 0; i--)
		pMem[i] = (~pMem[i]) & 0x00FFFFFF;
}

void Algorithm::Sketch()	// 素描
{
	// 定义指向灰度图和高斯模糊图的指针
	IMAGE* gray, * guassian;
	// 计算图像直方图
	Histogram();
	// 灰度处理
	Gray();
	// 创建灰度图
	gray = new IMAGE();
	// 创建高斯模糊图
	guassian = new IMAGE();
	// 将pimg赋值给gray
	*gray = *pimg;
	// 底片处理
	Film();

	// 进行10次模糊化处理
	for (int i = 0; i < 10; i++)
	{
		Blur(); // 模糊算法
	}
	// 将pimg赋值给guassian
	*guassian = *pimg;
	// 将pimg赋值为gray
	*pimg = *gray;

	// 获取pimg、gray、guassian的像素缓冲区指针
	DWORD* pMem = GetImageBuffer(pimg);
	DWORD* Gray = GetImageBuffer(gray);
	DWORD* Guassian = GetImageBuffer(guassian);

	int R, G, B;
	int RR, GG, BB;
	// 处理每一个像素
	for (int i = WIDTH * HEIGHT - 1; i >= 0; i--)
	{
		// 获取灰度图像素的R、G、B分量
		R = GetRValue(Gray[i]);
		B = GetBValue(Gray[i]);
		G = GetGValue(Gray[i]);
		// 获取高斯模糊图像素的R、G、B分量
		RR = GetRValue(Guassian[i]);
		BB = GetBValue(Guassian[i]);
		GG = GetGValue(Guassian[i]);
		// 计算每个像素的新的R、G、B分量
		int r = min(R + (R * RR) / (255 - RR), 255);
		int g = min(G + (G * GG) / (255 - GG), 255);
		int b = min(B + (B * BB) / (255 - BB), 255);
		// 将新的R、G、B分量组合成一个像素，并存储到pimg的像素缓冲区中
		pMem[i] = RGB(r, g, b);
	}
	// 释放gray和guassian所占用的内存
	delete (gray);
	delete(guassian);
}


void Algorithm::Histogram()		// 类似直方图
{
	DWORD* p_data = GetImageBuffer(pimg);
	int height = HEIGHT;
	int wide = WIDTH;
	int pr[256], pg[256], pb[256];
	int size = HEIGHT * WIDTH;
	for (int p = 0; p <= 255; p++)
	{
		int nr = 0, ng = 0, nb = 0;
		for (int j = 0; j < height; j++)
		{
			for (int i = 0; i < wide; i++)
			{
				if (p == GetRValue(p_data[j * wide + i]))
				{
					nr++;
				}
				if (p == GetGValue(p_data[j * wide + i]))
				{
					ng++;
				}
				if (p == GetBValue(p_data[j * wide + i]))
				{
					nb++;
				}
			}
		}
		pr[p] = nr;
		pg[p] = ng;
		pb[p] = nb;
	}
	double sr[256] = { 0 }, sg[256] = { 0 }, sb[256] = { 0 };
	double aver = 0;
	double aveg = 0;
	double aveb = 0;
	bool T = true;
	bool K = true;
	bool P = true;
	int numr, numg, numb;
	for (int i = 0; i <= 255; i++)
	{
		if (T)
		{
			aver += pr[i] / double(size);
			sr[i] = aver;
			if (aver == 1)
			{
				numr = i;
				T = false;
			}
		}
		if (K)
		{
			aveg += pg[i] / double(size);
			sg[i] = aveg;
			if (aveg == 1)
			{
				numg = i;
				K = false;
			}
		}
		if (P)
		{
			aveb += pb[i] / double(size);
			sb[i] = aveb;
			if (aveb == 1)
			{
				numb = i;
				P = false;
			}
		}
	}
	int ssr[256] = { 0 }, ssg[256] = { 0 }, ssb[256] = { 0 };
	int rx = 0, gx = 0, bx = 0;
	for (int i = 0; i <= 255; i++)
	{
		if (i == 0)
		{
			ssr[i] = 0;
			ssg[i] = 0;
			ssb[i] = 0;
		}
		ssr[i] = (int)(255 * sr[i]);
		ssg[i] = (int)(255 * sg[i]);
		ssb[i] = (int)(255 * sb[i]);
	}

	int r = 0, g = 0, b = 0;
	double myr = 0, myg = 0, myb = 0;
	for (int j = 0; j < height; j++)
	{
		for (int i = 0; i < wide; i++)
		{
			myr = ssr[GetRValue(p_data[j * wide + i])];
			myg = ssg[GetGValue(p_data[j * wide + i])];
			myb = ssb[GetBValue(p_data[j * wide + i])];
			p_data[j * wide + i] = RGB(myr, myg, myb);
		}
	}
};

void Algorithm::Gray()
{
	DWORD* p = GetImageBuffer(pimg);
	COLORREF c;
	for (int i = pimg->getwidth() * pimg->getheight() - 1; i >= 0; i--)
	{
		c = BGR(p[i]);
		c = (GetRValue(c) * 299 + GetGValue(c) * 587 + GetBValue(c) * 114 + 500) / 1000;
		p[i] = RGB(c, c, c);		// 由于是灰度值，无需再执行 BGR 转换
	}
}

void Algorithm::Blur()
{
	GetP();
	BYTE* R;
	BYTE* G;
	BYTE* B;
	int size = HEIGHT * WIDTH;
	R = (BYTE*)calloc(size, sizeof(BYTE));
	G = (BYTE*)calloc(size, sizeof(BYTE));
	B = (BYTE*)calloc(size, sizeof(BYTE));

	DWORD* pMem = GetImageBuffer(pimg);

	for (int i = 0; i < size; i++)
	{
		R[i] = GetRValue(pMem[i]);
		G[i] = GetGValue(pMem[i]);
		B[i] = GetBValue(pMem[i]);
	}

	for (int i = WIDTH; i < WIDTH * (HEIGHT - 1); i++)
	{
		if (i % 500 != 0 || (i + 1) % 500 != 0)
		{
			pMem[i] = RGB(R[i - (WIDTH + 1)] * P[0][0] + R[i - WIDTH] * P[0][1] + R[i - (WIDTH - 1)] * P[0][2] + R[i - 1] * P[1][0] + R[i] * P[1][1] + R[i + 1] * P[1][2] + R[i + (WIDTH - 1)] * P[2][0] + R[i + WIDTH] * P[2][1] + R[i + (WIDTH + 1)] * P[2][2],
				G[i - (WIDTH + 1)] * P[0][0] + G[i - WIDTH] * P[0][1] + G[i - (WIDTH - 1)] * P[0][2] + G[i - 1] * P[1][0] + G[i] * P[1][1] + G[i + 1] * P[1][2] + G[i + (WIDTH - 1)] * P[2][0] + G[i + WIDTH] * P[2][1] + G[i + (WIDTH + 1)] * P[2][2],
				B[i - (WIDTH + 1)] * P[0][0] + B[i - WIDTH] * P[0][1] + B[i - (WIDTH - 1)] * P[0][2] + B[i - 1] * P[1][0] + B[i] * P[1][1] + B[i + 1] * P[1][2] + B[i + (WIDTH - 1)] * P[2][0] + B[i + WIDTH] * P[2][1] + B[i + (WIDTH + 1)] * P[2][2]);
		}
	}
	free(R);
	free(G);
	free(B);
	R = G = B = NULL;
}

void GetP()
{
	for (int i = 0; i < pic_Dis; i++)
	{
		for (int j = 0; j < pic_Dis; j++)
		{
			int d = (i - 1) * (i - 1) + (j - 1) * (j - 1);
			double x = 1 / (2 * PI * delta);
			P[i][j] = x * exp(-d / (2 * delta));
		}
	}

	double pn = 0;

	for (int i = 0; i < pic_Dis; i++)
	{
		for (int j = 0; j < pic_Dis; j++)
		{
			pn += P[i][j];
		}
	}

	for (int i = 0; i < pic_Dis; i++)
	{
		for (int j = 0; j < pic_Dis; j++)
		{
			P[i][j] = P[i][j] / pn;
		}
	}
}

int main()
{
	// 初始化宽度和高度为0
	int width = 0;
	int height = 0;
	// 创建一个IMAGE对象g_img
	IMAGE g_img;
	// 加载图片"liuyifei.jpg"到g_img中
	loadimage(&g_img, _T("liuyifei.jpg"));
	// 获取图片宽度和高度，并赋值给width和height
	width = g_img.getwidth();
	height = g_img.getheight();
	// 创建一个Algorithm对象myA，传入g_img、width和height
	Algorithm myA(&g_img, width, height);
	// 初始化图形界面，窗口大小为width * height
	initgraph(width, height);
	// 对g_img进行素描处理
	myA.Sketch();
	// 将处理后的g_img显示在屏幕上，位置为(0,0)
	putimage(0, 0, &g_img);
	// 等待用户按下任意键
	_getch();
	// 程序结束，返回0
	return 0;
}