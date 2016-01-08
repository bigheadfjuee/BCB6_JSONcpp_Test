//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "TntStdCtrls.hpp"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
  TButton *btnTest;
  TTntMemo *mmoLog;
  TButton *btnJSON1;
  TButton *btnJSON2;
  TMemo *Memo1;
  void __fastcall btnTestClick(TObject *Sender);
  void __fastcall btnJSON1Click(TObject *Sender);
  void __fastcall btnJSON2Click(TObject *Sender);
private:	// User declarations
    char m_szLog[2048];
    void __stdcall OutputLog(LPCSTR lpMsg, ...);
public:		// User declarations
  __fastcall TForm1(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
