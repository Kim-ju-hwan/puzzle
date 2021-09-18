#include <bangtal>
using namespace bangtal;

bool change(ObjectPtr object1, ObjectPtr object2)
{
	object1->pick();
	object2->pick();

	return true;
}

int main()
{
	ScenePtr scene;
	//필요없는 옵션 제거
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	scene = Scene::create("퍼즐 ", "Images/배경.png");

	//60초 제한 설정
	auto timer1 = Timer::create(60);
	showTimer(timer1);
	timer1->start();

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

	//위치 설정
	int x[3] = { 255,425,590 };
	int y[3] = { 400,660,915 };
	auto piece1 = Object::create("Images/모나리자1.png", scene,x[0], y[2]);
	piece1->setScale(0.5f);
	auto piece2 = Object::create("Images/모나리자2.png", scene, x[1], y[2]);
	piece2->setScale(0.5f);
	auto piece3 = Object::create("Images/모나리자3.png", scene, x[2], y[2]);
	piece3->setScale(0.5f);
	auto piece4 = Object::create("Images/모나리자4.png", scene, x[0], y[1]);
	piece4->setScale(0.5f);
	auto piece5 = Object::create("Images/모나리자5.png", scene, x[1], y[1]);
	piece5->setScale(0.5f);
	auto piece6 = Object::create("Images/모나리자6.png", scene, x[2], y[1]);
	piece6->setScale(0.5f);
	auto piece7 = Object::create("Images/모나리자7.png", scene, x[0], y[0]);
	piece7->setScale(0.5f);
	auto piece8 = Object::create("Images/모나리자8.png", scene, x[1], y[0]);
	piece8->setScale(0.5f);
	auto blank = Object::create("Images/빈칸.png", scene, x[2], y[0]);
	blank->setScale(0.5f);
	
	int count = 0;
	auto button = Object::create("Images/성공.png", scene, 0, 400);
	button->setScale(0.2f);
	button->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();
		return true;
		});

	

	showMessage("제한시간은 1분! 퍼즐을 풀어보세요, 버튼을 누르면 종료됩니다.");
	startGame(scene);
}