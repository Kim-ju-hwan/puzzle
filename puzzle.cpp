#define _CRT_SECURE_NO_WARNINGS
#include <bangtal>
using namespace bangtal;

#include<cstdlib>
#include<ctime>

int blank;
ObjectPtr piece[9], original[9];
ScenePtr scene;

//조각들 위치 설정
const int x[3] = { 255,430,605 };
const int y[3] = { 400,660,920 };

int game_index(ObjectPtr object) {
	for (int i = 0;i < 9;i++) {
		if (piece[i] == object)	return i;
	};
}

//index와 blank를 바꿔준다.
void game_move(int index)
{
	ObjectPtr temp = piece[index];
	piece[index] = piece[blank];
	piece[index]->locate(scene, x[index % 3], y[2 - index / 3]);
	piece[blank] = temp;
	piece[blank]->locate(scene, x[blank % 3], y[2 - blank / 3]);
	blank = index;
}

//빈칸옆인지 확인하는 함수
bool check(int index) {
	if (blank %3>0 && index == blank - 1) return true;
	if (blank %3<2 && index == blank + 1) return true;
	if (index == blank - 3)  return true;
	if (index == blank + 3)	 return true;

	return false;
}

//랜덤으로 숫자를 뽑는다.
int randmove() {
	int index = rand() % 9;
	return index;
}

//셔플해주는 함수
void game_set() {
	for (int i = 0;i < 10;i++) {
		game_move(randmove());
	}
}

//게임 종료를 확인
bool checkend() {
	for (int i = 0;i < 9;i++) {
		if (original[i] != piece[i]) return false;
	}
	return true;
}

//게임의 진행을 하는 함수
void Start() {
	scene = Scene::create("퍼즐 ", "Images/배경.png");
	char path[30];
	//60초 타이머 생성
	auto timer1 = Timer::create(60);
	showTimer(timer1);

	timer1->setOnTimerCallback([&](TimerPtr timer)->bool {
		showMessage("실패ㅠㅠ");
		auto timer2 = Timer::create(1);
		timer2->start();

		timer2->setOnTimerCallback([&](TimerPtr timer)->bool {
			endGame();
			return true;
			});
		return true;
		});

	long long t1;
	//시작하는 버튼 생성
	auto button = Object::create("Images/시작.png", scene, 0, 400);
	button->setScale(0.2f);
	button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		timer1->start();
		button->hide();
		game_set();
		showMessage("게임 시작!");
	     t1 = time(NULL);
		return true;
		});

	for (int i = 0;i < 9;i++)
	{
		sprintf(path, "Images/모나리자_00%d.JPEG", i + 1);
		piece[i] = Object::create(path, scene, x[i % 3], y[2 - i / 3]);
		piece[i]->setScale(0.5f);
		piece[i]->setOnMouseCallback([&](auto object, int x, int y, auto action)->bool {
			int num = game_index(object);
			if (check(num)) {
				game_move(num);
				if (checkend()) {
					timer1->stop();
					long long t2= time(NULL);
					int a = t2 - t1;
					char s1[100];
					sprintf(s1, "성공!!!!!! %d초 걸렸습니다.", a);
					showMessage(s1);
					auto timer2 = Timer::create(1);
					timer2->start();

					timer2->setOnTimerCallback([&](TimerPtr timer)->bool {
						endGame();
						return true;
						});
				}
			}
			return true;
			});
		original[i] = piece[i];
	}
	blank = 8;
	piece[blank]->hide();

	


	//게임방법 설명하는 버튼 생성
	auto howto = Object::create("Images/게임방법.png", scene, 0, 1000);
	howto->setScale(0.8f);

	auto explain = Object::create("Images/how.png", scene, 150, 450, false);


	howto->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		explain->show();
		return true;
		});

	explain->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		explain->hide();
		return true;
		});

	startGame(scene);
}

int main()
{
	srand((unsigned int)time(NULL));
	//필요없는 옵션 제거
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	Start();
}