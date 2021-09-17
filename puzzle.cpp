#include <bangtal>
using namespace bangtal;


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
	int x1=255, x2=425, x3=595;
	int y1=400, y2=660, y3=920;
	auto piece1 = Object::create("Images/모나리자1.png", scene,x1, y3);
	piece1->setScale(0.5f);
	auto piece2 = Object::create("Images/모나리자2.png", scene, x2, y3);
	piece2->setScale(0.5f);
	auto piece3 = Object::create("Images/모나리자3.png", scene, x3, y3);
	piece3->setScale(0.5f);
	auto piece4 = Object::create("Images/모나리자4.png", scene, x1, y2);
	piece4->setScale(0.5f);
	auto piece5 = Object::create("Images/모나리자5.png", scene, x2, y2);
	piece5->setScale(0.5f);
	auto piece6 = Object::create("Images/모나리자6.png", scene, x3, y2);
	piece6->setScale(0.5f);
	auto piece7 = Object::create("Images/모나리자7.png", scene, x1, y1);
	piece7->setScale(0.5f);
	auto piece8 = Object::create("Images/모나리자8.png", scene, x2, y1);
	piece8->setScale(0.5f);
	auto piece9 = Object::create("Images/모나리자9.jpg", scene, x3, y1);
	piece9->setScale(0.5f);
	showMessage("제한시간은 1분! 퍼즐을 풀어보세요!!");
	startGame(scene);
}

