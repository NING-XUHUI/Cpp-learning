#include <Windows.h>

//WINAPI 代表__std_call参数传递顺序，右到左入栈，函数返回时清栈
int WINAPI WinMain(HINSTANCE hInstance,//应用程序实例句柄
                   HINSTANCE hPreInstance,//上一个应用程序实力句柄，参数一般为NULL
                   LPSTR lpCmdLine,//char *argv[]
                   int nShowCmd)//显示命令
{
    //1.设计窗口
    WNDCLASS wc;
    wc.cbClsExtra = 0;//类的额外内存
    wc.cbWndExtra = 0;//窗口额外内存
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);//设置背景颜色
    wc.hCursor = LoadCursor(NULL, IDC_HAND);//设置光标，如果第一个值为NULL，则使用系统默认光标
    wc.hIcon = LoadIcon(NULL, IDI_ERROR);//设置图标，如果第一个值为NULL，则使用默认图标
    wc.hInstance = hInstance;//实例句柄使用传进来的参数即可
    wc.lpfnWndProc = WindowProc;//回调函数，窗口过程
    wc.lpszClassName = TEXT("WIN");//窗口类的名称
    wc.lpszMenuName = NULL;//菜单名称
    wc.style = 0;//显示风格，0表示默认风格

    //2.注册窗口
    RegisterClass(&wc);

    //3.创建窗口
    /*
     * lpClassName 类名
     * lpWindowName 标题名
     * dwStyle WS_OVERLAPPEDWINDOW 风格
     * x 坐标
     * y
     * width CW_USEDEFAULT
     * height
     * hWndParent 父类窗口NULL
     * hMenu 菜单NULL
     * hInstance 实例句柄
     * plParam 附加值，鼠标附加值
     *
     */
    HWND hwnd = CreateWindow(wc.lpszClassName, TEXT("WINDOWS"), WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
                             NULL, hInstance, NULL);


    //4.显示以及更新
    ShowWindow(hwnd, SW)SHOWNORMAL;
    UpdateWindow(hwnd);

    //5.取消息
}
