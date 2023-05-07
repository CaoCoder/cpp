
#include <graphics.h>

#define MAX_STAR 500			// ѩ����������
#define SCREEN_WIDTH 640		// ��Ļ���
#define SCREEN_HEIGHT 480		// ��Ļ�߶�
#define MAX_STEP 3				// ѩ��ÿ���ƶ���߲���
#define MAX_RADIUS 3			// ѩ�����뾶
#define IMGNAME _T("img.jpg")	// ͼƬ����

using namespace std;

// ͼƬת���飨����кܴ��Ż��ռ�ģ���Ҫʶ���ɫ��Ƭ���Կ��⣩
int imgList[SCREEN_HEIGHT][SCREEN_WIDTH] = { 0 };

// ѩ��״̬
enum STATUS
{
	STOP = 0,	// ����
	UP,			// ����
	DOWN,		// ����
	LEFT,		// ����
	RIGHT,		// ����
	RANDOM,		// ���
	ALL_STATUS	// ��¼״̬����
};
struct STAR
{
	int x;				// ѩ���� x ����
	int y;				// ѩ���� y ����
	enum STATUS stat;	// ѩ��״̬
	unsigned radius;	// ѩ���İ뾶
	int step;			// ѩ��ÿ���ƶ��Ĳ���
	int color;			// ѩ������ɫ
};
struct SqList
{
	struct STAR* elems; // ˳���Ļ���ַ
	int length;			// ˳���ĳ���
	int size;			// ˳���Ŀռ�
};

// �ӿ�����
bool initList(SqList& L);
bool listAppend(SqList& L, struct STAR e);
bool listDelete(SqList& L, int i);
void destroyList(SqList& L);

// ��ʼ��˳���
bool initList(SqList& L) {
	L.elems = new struct STAR[MAX_STAR]; // Ϊ˳������洢�ռ�
	if (!L.elems) return false; // �������洢�ռ�ʧ�ܣ��򷵻� false
	L.length = 0; // ��ʼ����Ϊ0
	L.size = MAX_STAR; // ��ʼ����ռ��СΪMAX_STAR
	return true; // ���� true ��ʾ��ʼ���ɹ�
}

// ׷��Ԫ�ص�˳���ĩβ
bool listAppend(SqList& L, struct STAR e) {
	if (L.length == L.size) return false; // ���˳����������򷵻� false
	L.elems[L.length] = e; // ��Ԫ�� e ��ӵ����ĩβ
	L.length++; // ����1
	return true; // ���� true ��ʾ��ӳɹ�
}

// ɾ��˳�����ָ��λ�õ�Ԫ��
bool listDelete(SqList& L, int i) {
	if (i < 0 || i >= L.length) return false; // ����±� i ���Ϸ����򷵻� false
	for (int j = i; j < L.length - 1; j++) { // �� i ��������Ԫ����ǰ�ƶ�һλ
		L.elems[j] = L.elems[j + 1];
	}
	L.length--; // ����1
	return true; // ���� true ��ʾɾ���ɹ�
}

// ����˳���
void destroyList(SqList& L) {
	delete[] L.elems; // �ͷ�˳���Ĵ洢�ռ�
	L.length = 0; // �����ͱ�ռ���Ϊ0
	L.size = 0;
	L.elems = NULL; // ��ָ�� elems ��Ϊ null
}
/************************************
* ���ܣ��ƶ�ѩ��������ָ����������ѩ��
* ���������
* L - ѩ������
* i - ѩ����ȫ�������е��±�
* ����ֵ����
************************************/
// �ƶ�ѩ��
void MoveStar(SqList& L, int i) {
	// ����ѩ����ǰ��״̬�����ƶ�
	if (L.elems[i].stat == DOWN) { // ����Ʈ��
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // �����ǰλ���ǰ�ɫ������������ƶ�
			L.elems[i].y += L.elems[i].step; // �����ƶ�һ������
			L.elems[i].x -= 2; // ͬʱ�����ƶ�2�����أ�ʹѩ������Ʈ��Ч��
		}
	}
	else if (L.elems[i].stat == UP) { // ����Ʈ��
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // �����ǰλ���ǰ�ɫ������������ƶ�
			L.elems[i].y -= L.elems[i].step; // �����ƶ�һ������
			L.elems[i].x -= 2; // ͬʱ�����ƶ�2�����أ�ʹѩ������Ʈ��Ч��
		}
	}
	else if (L.elems[i].stat == LEFT) { // ����Ʈ��
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // �����ǰλ���ǰ�ɫ������������ƶ�
			L.elems[i].x -= L.elems[i].step; // �����ƶ�һ������
		}
	}
	else if (L.elems[i].stat == RIGHT) { // ����Ʈ��
		if (imgList[L.elems[i].y][L.elems[i].x] == 1) { // �����ǰλ���ǰ�ɫ������������ƶ�
			L.elems[i].x += L.elems[i].step; // �����ƶ�һ������
		}
	}

	// ���ѩ��״̬Ϊֹͣ����ֱ�ӷ���
	if (L.elems[i].stat == STOP) return;

	// ������ǰλ�õ�ѩ��
	// ���������ɫΪ��ɫ
	setfillcolor(BLACK); 
	// �ڵ�ǰλ�û���һ����ɫ��ʵ��Բ������ѩ��
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius); 
	// ����ѩ����ǰ��״̬�����ƶ���������λ�û���ѩ��
	if (L.elems[i].stat == DOWN) { // ����Ʈ��
		L.elems[i].y += L.elems[i].step; // �����ƶ�һ������
		L.elems[i].x -= 2; // ͬʱ�����ƶ�2�����أ�ʹѩ������Ʈ��Ч��
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH; // ���ѩ���Ѿ�Ʈ����Ļ��࣬�����Ƶ���Ļ�Ҳ�
		if (L.elems[i].y > SCREEN_HEIGHT) L.elems[i].y = 0; // ���ѩ���Ѿ�Ʈ����Ļ�·��������Ƶ���Ļ����
		//if(L.elems[i].y>SCREEN_HEIGHT) listDelete(L, i);	// ��δ��������Ʈ����Ļ���ѩ������
	}
	else if (L.elems[i].stat == UP) { // ����Ʈ��
		L.elems[i].y -= L.elems[i].step; // �����ƶ�һ������
		L.elems[i].x -= 2; // ͬʱ�����ƶ�2�����أ�ʹѩ������Ʈ��Ч��
		if (L.elems[i].x < 0) L.elems[i].x = SCREEN_WIDTH; // ���ѩ���Ѿ�Ʈ����Ļ��࣬�����Ƶ���Ļ�Ҳ�
		if (L.elems[i].y < 0) L.elems[i].y = SCREEN_HEIGHT; // ���ѩ���Ѿ�Ʈ����Ļ�����������Ƶ���Ļ�·�
		//if(L.elems[i].y<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == LEFT) { // ����Ʈ��
		L.elems[i].x -= L.elems[i].step; // �����ƶ�һ������
		if (L.elems[i].x > 0) L.elems[i].x = SCREEN_WIDTH; // ���ѩ���Ѿ�Ʈ����Ļ�Ҳ࣬�����Ƶ���Ļ���
		//if(L.elems[i].x<0) listDelete(L, i);
	}
	else if (L.elems[i].stat == RIGHT) { // ����Ʈ��
		L.elems[i].x += L.elems[i].step; // �����ƶ�һ������
		if (L.elems[i].x > SCREEN_HEIGHT) L.elems[i].x = 0; // ���ѩ���Ѿ�Ʈ����Ļ��࣬�����Ƶ���Ļ�Ҳ�
		//if(L.elems[i].x>SCREEN_WIDTH) listDelete(L, i);
	}

	// ����λ�û���ѩ��
	setfillcolor(L.elems[i].color); // ���������ɫΪѩ������ɫ
	solidcircle(L.elems[i].x, L.elems[i].y, L.elems[i].radius); // ����λ�û���һ��ʵ��Բ����ʾѩ��
}


/************************************
* ���ܣ���ʼ��ѩ��
* ���������
* i - ѩ����ȫ�������е��±�
* ����ֵ����
************************************/
void initStar(struct STAR& _star)
{
	int rgb = 0;
	//rand() �õ��������Χ 0 - 32767 RAND_MAX
	_star.x = rand() % SCREEN_WIDTH;		// x ��Χ 0 - SCREEN_WIDTH
	_star.y = rand() % SCREEN_HEIGHT;		// y ��Χ 0 - SCREEN_HEIGHT
	//_star.stat = STATUS(rand() % 6);		// ѩ��״̬�����
	_star.stat = DOWN;						// ѩ��״̬������
	_star.radius = 1 + rand() % MAX_RADIUS; // �뾶���� 1 - MAX_RADIUS
	_star.step = rand() % MAX_STEP + 1;		// ���� 1 - MAX_STEP
	rgb = 255 * _star.step / MAX_STEP;		// RGB��0 - 255
	_star.color = RGB(rgb, rgb, rgb);
}


int main()
{
	bool quit = false; // ����Ƿ��˳�����
	struct STAR star; // ����һ��ѩ���ṹ��
	SqList starList; // ����һ��˳������ڱ�������ѩ����״̬

	// ��ʼ����Ļ
	initgraph(SCREEN_WIDTH, SCREEN_HEIGHT);

	// ��ʼ��ͼƬ
	IMAGE img;
	loadimage(&img, IMGNAME); // ����ָ�����Ƶ�ͼƬ
	SetWorkingImage(&img); // ��ͼƬ����Ϊ�����豸
	COLORREF color; // ����һ��COLORREF���ͱ��������ڴ洢������ɫ
	BYTE r, b, g; // ��������BYTE���ͱ��������ڴ洢���ص�RGBֵ

	// ����ͼƬ���������أ���¼��Ҫ���¡�ѩ�ۡ���λ��
	for (int y = 0; y < SCREEN_HEIGHT; y++)
	{
		for (int x = 0; x < SCREEN_WIDTH; x++)
		{
			color = getpixel(x, y); // ��ȡ��ǰ���ص����ɫ
			r = GetRValue(color); // ��ȡ���ص�ĺ�ɫ����
			b = GetBValue(color); // ��ȡ���ص����ɫ����
			g = GetGValue(color); // ��ȡ���ص����ɫ����
			if (r < 200 && b < 200 && g < 200) // �жϵ�ǰ���ص��Ƿ���Ҫ���¡�ѩ�ۡ�
			{
				imgList[y][x] = 1; // ����ǰ���ص���Ϊ��Ҫ���¡�ѩ�ۡ���λ��
			}
		}
	}

	SetWorkingImage(); // �������豸���û�Ĭ��
	cleardevice(); // �����Ļ

	// ��ʼ������ѩ��״̬��˳���
	initList(starList);

	// ������� MAX_STAR ��ѩ����������״̬���浽˳�����
	for (int i = 0; i < MAX_STAR; i++)
	{
		initStar(star); // ��ʼ��һ��ѩ��״̬
		listAppend(starList, star); // ����ѩ��״̬���浽˳�����
	}

	// ����Ļ�ϻ�������ѩ��
	for (int i = 0; i < starList.length; i++)
	{
		setfillcolor(starList.elems[i].color); // ���õ�ǰѩ���������ɫ
		solidcircle(starList.elems[i].x, starList.elems[i].y,
			starList.elems[i].radius); // ����Ļ�ϻ��Ƶ�ǰѩ��
	}

	// ������ѩ����ʼƮ��
	while (quit == false)
	{
		for (int i = 0; i < starList.length; i++)
		{
			MoveStar(starList, i); // �ƶ���ǰѩ��
		}

		if (starList.length == 0) // ������ѩ���뿪��Ļ����������ᴥ�����˳�
		{
			quit = true;
		}

		Sleep(50); // �ȴ�һ��ʱ�䣬ʹѩ��Ʈ��Ч��������Ȼ
	}

	system("pause"); // ��ͣ���򣬵ȴ��û����������
	closegraph(); // �ر�ͼ�ν���
	return 0;
}