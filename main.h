#define G_NUM = 9.8 // 重力加速度
#define TIME_STEP 1 // 1秒間に何秒進めるか
#define FRAME_RATE 1/60 // 描画の関数が呼ばれる時間

struct Obj {
    double x, y; // 座標
    double vx, vy; // 速度
    double ax, ay; // 加速度
    int size; // 大きさ
};
