//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Imaging.jpeg.hpp>
#include <Vcl.Menus.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TLabel *Label2;
	TEdit *Edit4;
	TLabel *Label3;
	TEdit *Edit2;
	TLabel *Label4;
	TEdit *Edit3;
	TTimer *Timer1;
	TButton *Button2;
	TButton *Button3;
	TEdit *Edit1;
	TButton *Button1;
	TLabel *Label5;
	TMemo *Memo1;
	TLabel *Label1;
	void __fastcall N1Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
