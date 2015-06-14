﻿#ifndef GUI_H
#define GUI_H
#include <iostream>
#include <string>
#include <iomanip> //setw()
#include <thread>
#include "Map.h"
#pragma comment(lib, "winmm.lib")  //PlaySound
using std::cout;
using std::string;

#define WINDOW_COLS 104
#define WINDOW_LINES 24
#define BATTLE_SITUATION_LINES 20
#define KB_UP 72     //鍵盤輸入數值 上
#define KB_DOWN 80   //鍵盤輸入數值 下
#define KB_LEFT 75   //鍵盤輸入數值 左
#define KB_RIGHT 77  //鍵盤輸入數值 右
#define KB_ENTER 13  //鍵盤輸入數值 Enter
#define KB_ESC 27    //鍵盤輸入數值 ESC
#define CHESSMAP_SIZE_ROW 17      //棋盤ROW    SIZE
#define CHESSMAP_SIZE_COLUMN 19   //棋盤column SIZE
#define WD_BLACK_BG_WHITE 240     //黑字白色背景
#define WD_RED_BG_WHITE 252       //紅字白色背景
#define CHESS_RED 124             //紅方旗子的顏色
#define CHESS_BLACK 112           //黑方棋子的顏色
#define WD_Purple_BG_WHITE 253    //紫色字白色背景
#define WD_RED_BG_BLACK 12        //紅字黑色背景
#define WD_OCEANBLUE_BG_BLACK 11  //水藍色字黑色背景
#define WD_GRAY_BG_BLACK 8        //灰色字黑色背景
#define DEFAULT_COLOR 7           //預設白字黑色背景
#define SHOW_WHOS_TURN_POS ComXY(40,2)       //顯示哪一方下棋的座標
#define SHOW_WHAT_YOU_CHOSE_POS ComXY(40, 4) //顯示你選取哪個棋子的座標
#define CHESS_BOARD_X 29           //棋盤基準點X
#define CHESS_BOARD_Y 1           //棋盤基準點Y
#define KB_44 44   //Keyboard "<"
#define KB_46 46   //Keyboard ">"
#define MID_X srInfo.srWindow.Right/2
#define MID_Y srInfo.srWindow.Bottom/2

/**************棋盤*****************/
const char ChessScreenChar[21][35] = {
	"１　２　３　４　５　６　７　８　９",
	"╔═╤═╤═╤═╤═╤═╤═╤═╗",
	"║　│　│　│╲│╱│　│　│　║",
	"║─┼─┼─┼─┼─┼─┼─┼─║",
	"║　│　│　│╱│╲│　│　│　║",
	"║─┼─┼─┼─┼─┼─┼─┼─║",
	"║　│　│　│　│　│　│　│　║",
	"║─┼─┼─┼─┼─┼─┼─┼─║",
	"║　│　│　│　│　│　│　│　║",
	"║─┴─┴─┴─┴─┴─┴─┴─║" ,
	"║　　楚河　　　　　　漢界　　　║",
	"║─┬─┬─┬─┬─┬─┬─┬─║",
	"║　│　│　│　│　│　│　│　║",
	"║─┼─┼─┼─┼─┼─┼─┼─║",
	"║　│　│　│　│　│　│　│　║",
	"║─┼─┼─┼─┼─┼─┼─┼─║",
	"║　│　│　│╲│╱│　│　│　║",
	"║─┼─┼─┼─┼─┼─┼─┼─║",
	"║　│　│　│╱│╲│　│　│　║",
	"╚═╧═╧═╧═╧═╧═╧═╧═╝",
	"九　八　七　六　五　四　三　二　一" };

const string ChessScreen[CHESSMAP_SIZE_COLUMN][CHESSMAP_SIZE_ROW] =
{ { "╔", "═", "╤", "═", "╤", "═", "╤", "═", "╤", "═", "╤", "═", "╤", "═", "╤", "═", "╗" },
{ "║", "　", "│", "　", "│", "　", "│", "╲", "│", "╱", "│", "　", "│", "　", "│", "　", "║" },
{ "║", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "║" },
{ "║", "　", "│", "　", "│", "　", "│", "╱", "│", "╲", "│", "　", "│", "　", "│", "　", "║" },
{ "║", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "║" },
{ "║", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "║" },
{ "║", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "║" },
{ "║", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "║" },
{ "║", "─", "┴", "─", "┴", "─", "┴", "─", "┴", "─", "┴", "─", "┴", "─", "┴", "─", "║" },
{ "║", "　", "　", "楚", "河", "　", "　", "　", "　", "　", "　", "漢", "界", "　", "　", "　", "║" },
{ "║", "─", "┬", "─", "┬", "─", "┬", "─", "┬", "─", "┬", "─", "┬", "─", "┬", "─", "║" },
{ "║", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "║" },
{ "║", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "║" },
{ "║", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "│", "　", "║" },
{ "║", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "║" },
{ "║", "　", "│", "　", "│", "　", "│", "╲", "│", "╱", "│", "　", "│", "　", "│", "　", "║" },
{ "║", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "┼", "─", "║" },
{ "║", "　", "│", "　", "│", "　", "│", "╱", "│", "╲", "│", "　", "│", "　", "│", "　", "║" },
{ "╚", "═", "╧", "═", "╧", "═", "╧", "═", "╧", "═", "╧", "═", "╧", "═", "╧", "═", "╝" } };

const char mainMenuScreen[WINDOW_LINES][WINDOW_COLS + 1] = {
	"╔══════════════════════════════════════════════════╗",
	"║    ,o888888o.    8888        8888  8888  b.            88  888888888888   d888888o.    888888888888║",
	"║  ,8888     `88.  8888        8888  8888  888o.         88  8888         .88888:' `88.  8888        ║",
	"║,888888       `8. 8888        8888  8888  888888o.      88  8888         8888888.   Y8  8888        ║",
	"║8888888           8888        8888  8888  888888888o.   88  8888         `8888888.      8888        ║",
	"║8888888           8888        8888  8888  888888888888o.88  8888          `8888888.     8888        ║",
	"║8888888           8888888888888888  8888  88Y8888888888888  888888888888   `8888888.    888888888888║",
	"║8888888           8888        8888  8888  88  `Y8888888888  8888            `8888888.   8888        ║",
	"║`888888       .8' 8888        8888  8888  88     `Y8888888  8888        8b   `8888888.  8888        ║",
	"║  `8888     ,88'  8888        8888  8888  88        `Y8888  8888        `8b.  ;8888888  8888        ║",
	"║    `8888888P'    8888        8888  8888  88           `Yo  888888888888 `Y888888888P'  888888888888║",
	"║                                                                                                    ║",
	"║                                                 ╔════╗                                       ║",
	"║    ,o888888o.    8888        8888  888888888888 ║        ║    d888888o.       d888888o.          ║",
	"║  ,8888     `88.  8888        8888  8888         ╠════╣  .88888:' `88.   .88888:' `88.        ║",
	"║,888888       `8. 8888        8888  8888         ║        ║  8888888.   Y8   8888888.   Y8        ║",
	"║8888888           8888        8888  8888         ╠════╣  `8888888.       `8888888.            ║",
	"║8888888           8888        8888  8888         ║        ║   `8888888.       `8888888.           ║",
	"║8888888           8888888888888888  888888888888 ╠════╣    `8888888.       `8888888.          ║",
	"║8888888           8888        8888  8888         ║        ║     `8888888.       `8888888.         ║",
	"║`888888       .8' 8888        8888  8888         ╠════╣ 8b   `8888888.  8b   `8888888.        ║",
	"║  `8888     ,88'  8888        8888  8888         ║        ║ `8b.  ;8888888  `8b.  ;8888888        ║",
	"║    `8888888P'    8888        8888  888888888888 ╚════╝  `Y888888888P'   `Y888888888P'        ║",
	"╚══════════════════════════════════════════════════╝" };
const char gameScreen[WINDOW_LINES][WINDOW_COLS+1] = {
	"╔══════════════════════════════════════════════════╗",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"║                                                                                                    ║",
	"╚══════════════════════════════════════════════════╝" };
const char gameInfoScreen[22][39] = {  //22*38
	"╔═════════════════╗",
	"║                                  ║",
	"║                                  ║",
	"║      現在輪到          下棋      ║",
	"║                                  ║",
	"║                                  ║",
	"║                                  ║",
	"║                                  ║",
	"║                                  ║",
	"║                                  ║",
	"║                                  ║",
	"║                                  ║",
	"║                                  ║",
	"╠═════════════════╣",
	"║   Esc 選單    < 悔棋    > 還原   ║",
	"║                                  ║",
	"║      Enter     選取棋子          ║",
	"║                                  ║",
	"║        ↑                        ║",
	"║      ←  →  方向鍵控制游標      ║",
	"║        ↓                        ║",
	"╚═════════════════╝" };
const char aboutScreen[WINDOW_LINES][WINDOW_COLS + 1] = {
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　本遊戲為　１０３－２　程式設計ＡＡ期末專題　第三組　之專題成果　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　第三組　成員：　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　組長　陳冠羽　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　組員　袁艾文　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　張岱　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　林福廷　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　曾翊華　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　李至曜　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　指導助教　莊正陽　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　",
	"　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　　" };
class GUI {
public:
	GUI();
	~GUI();
	short mainMenu();    //  1=start ; 2=setting ; 3=exit
	short MenuInGame();  //  1=resume ; 2=restart ; 3=exit
	void setVisible(bool);
	void dwSize(int);
	//--------------------
	void displayGameScreen(const Map& map, bool isWhosTurn, const Chess *ch = nullptr);
	void displayChessboard(const Map&);
	void displayGameInfo(bool,const Map&, const Chess *ch = nullptr);
	void displayBattleSituation(const Map& map);
	//--------------------
	void displayPossiblePath(Chess* ch, const Map& map);
	bool showConfirm(const string&);          //<==請填剛好22半形字元
	void showAlert(const string, const short);//<==請填剛好22半形字元
	int showDepthInput();
	void displayExitScreen();
	void displayAboutScreen();
	void gotoxy(COORD);
	void gotoxy(short, short);
	void showTextColor(string, SHORT);
private:
	void setColor(INT);
};

#endif