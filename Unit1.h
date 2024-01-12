//---------------------------------------------------------------------------
#include <vcl.h>
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
#include <iostream>
#include <fstream>
#include <cstring>
#include <ctime>
#include <string>
#include <algorithm>
#include <numeric>
#include <system.hpp>
#include <vector>
using namespace std;
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TRadioButton *RadioButton1;
	TLabel *Label1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TButton *Button1;
	TMenuItem *N3;
	TMenuItem *N4;
	TMemo *Memo1;
	TMenuItem *N5;
	TMenuItem *N6;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
