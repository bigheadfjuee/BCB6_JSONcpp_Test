//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "TntStdCtrls"
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
  : TForm(Owner)
{
    mmoLog->ScrollBars = ssVertical;
    mmoLog->ReadOnly = true;
    mmoLog->Lines->Clear();
}
//---------------------------------------------------------------------------
#include <stdio.h>
#include "json/json.h"
void __fastcall TForm1::btnTestClick(TObject *Sender)
{
  Json::Value root, array;
  
  UTF8String utf8 = L"UTF8����A�i�H�ܡH";
  //AnsiString ansi = Utf8ToAnsi(utf8);

  array.append(utf8.c_str());
  array.append("�}�C2");
  array.append(3);
  root["MyArray"] = array;  

  UTF8String key, val;
  key = L"MyName";
  val = L"JSON����";
  root[key.c_str()] = val.c_str();

  UTF8String txt = root.toStyledString().c_str();                            
  mmoLog->Text = txt;
//  txt = StringReplace(txt, "\n", "", TReplaceFlags()<<rfReplaceAll); 

  Json::Reader reader;
  Json::Value root_R;
  reader.parse(txt.c_str(), root_R);
  
  Json::Value name = root_R["MyName"];
  Memo1->Lines->Add(name.asCString());
  
  Json::Value array_R = root_R["MyArray"];
  if (array_R.type() == Json::arrayValue)
  {
    for (size_t i = 0; i < array_R.size(); i++)
    {
      Json::Value val = array_R[i];
      if( val.type() == Json::stringValue)
        Memo1->Lines->Add(val.asCString());
      else if( val.type() == Json::intValue)
        Memo1->Lines->Add("��ơG" + AnsiString(val.asInt()));
    }
  }
}
//---------------------------------------------------------------------------
void __stdcall TForm1::OutputLog(LPCSTR lpMsg, ...)
{
	// �w�q�O�s��ưѼƪ����c
	va_list ap;

	// argp���V�ǤJ���Ĥ@�ӥi��Ѽ� msg�O�̦Z�@�ӽT�w���Ѽ�
	va_start(ap, lpMsg);

  memset(m_szLog, 0x0, sizeof(m_szLog));
	wvsprintfA(m_szLog, lpMsg, ap);

	mmoLog->Lines->Add(m_szLog);
	va_end(ap); // �Nargp�m��NULL
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnJSON1Click(TObject *Sender)
{
    char *lpFileName = "1.json";
    FILE *fp = fopen(lpFileName, "r");
    if (!fp)
    {
        OutputLog("��󥴶}����! %s", lpFileName);
        return;
    }

    // ���������
    fseek(fp, 0L, SEEK_END);
    long lSize = ftell(fp);
    // �w�q�����j���w�R
    char *lpBuffer = new char[lSize + 1];
    // Ū����󤺮e��w�R
    fseek(fp, 0, SEEK_SET);
    fread(lpBuffer, 1, lSize, fp);
    lpBuffer[lSize] = 0x0;
    // �������
    fclose(fp);

    Json::Reader reader;
    Json::Value root;
    reader.parse(lpBuffer, root);

    // ����w�R
    delete []lpBuffer;

    Json::Value address = root["address"];
    if (address.type() == Json::stringValue)
    {
        OutputLog("address: %s", Utf8ToAnsi(address.asCString()));
    }
    else
    {
        OutputLog("address Ū������, ����: %d", (int)address.type());
    }

    Json::Value content = root["content"];
    if (content.type() == Json::objectValue)
    {
        Json::Value address = content["address"];
        if (address.type() == Json::stringValue)
            OutputLog("content/address: %s", Utf8ToAnsi(address.asCString()));
        else
            OutputLog("content/address Ū������, ����: %d", (int)address.type());

        Json::Value address_detail = content["address_detail"];
        if (address_detail.type() == Json::objectValue)
        {
            Json::Value city = address_detail["city"];
            if (city.type() == Json::stringValue)
                OutputLog("content/address_detail/city: %s", Utf8ToAnsi(city.asCString()));
            else
                OutputLog("content/address_detail/city Ū������, ����: %d", (int)city.type());

            Json::Value city_code = address_detail["city_code"];
            if (city_code.type() == Json::intValue)
                OutputLog("content/address_detail/city_code: %d", city_code.asInt());
            else
                OutputLog("content/address_detail/city_code Ū������, ����: %d", (int)city_code.type());

            // 63 63 72 75 6E 2E 63 6F 6D
            Json::Value district = address_detail["district"];
            if (district.type() == Json::stringValue)
                OutputLog("content/address_detail/district: %s", Utf8ToAnsi(district.asCString()));
            else
                OutputLog("content/address_detail/district Ū������, ����: %d", (int)district.type());

            Json::Value province = address_detail["province"];
            if (province.type() == Json::stringValue)
                OutputLog("content/address_detail/province: %s", Utf8ToAnsi(province.asCString()));
            else
                OutputLog("content/address_detail/province Ū������, ����: %d", (int)province.type());

            Json::Value street = address_detail["street"];
            if (street.type() == Json::stringValue)
                OutputLog("content/address_detail/street: %s", Utf8ToAnsi(street.asCString()));
            else
                OutputLog("content/address_detail/street Ū������, ����: %d", (int)street.type());

            Json::Value street_number = address_detail["street_number"];
            if (street_number.type() == Json::stringValue)
                OutputLog("content/address_detail/street_number: %s", Utf8ToAnsi(street_number.asCString()));
            else
                OutputLog("content/address_detail/street_number Ū������, ����: %d", (int)street_number.type());
        }
        else
            OutputLog("content/address_detail Ū������, ����: %d", (int)address_detail.type());

        Json::Value point = content["point"];
        if (point.type() == Json::objectValue)
        {
            Json::Value x = point["x"];
            if (x.type() == Json::stringValue)
                OutputLog("content/point/x: %s", Utf8ToAnsi(x.asCString()));
            else
                OutputLog("content/point/x Ū������, ����: %d", (int)x.type());

            Json::Value y = point["y"];
            if (y.type() == Json::stringValue)
                OutputLog("content/point/y: %s", Utf8ToAnsi(y.asCString()));
            else
                OutputLog("content/point/y Ū������, ����: %d", (int)y.type());
        }
    }
    else
    {
        OutputLog("content Ū������, ����: %d", (int)content.type());
    }

    Json::Value status = root["status"];
    if (status.type() == Json::intValue)
        OutputLog("status: %d", status.asInt());
    else
        OutputLog("status Ū������, ����: %d", (int)status.type());
}
//---------------------------------------------------------------------------
void __fastcall TForm1::btnJSON2Click(TObject *Sender)
{
    char *lpFileName = "2.json";
    FILE *fp = fopen(lpFileName, "r");
    if (!fp)
    {
        OutputLog("��󥴶}����! %s", lpFileName);
        return;
    }

    // ���������
    fseek(fp, 0L, SEEK_END);
    long lSize = ftell(fp);
    // �w�q�����j���w�R
    char *lpBuffer = new char[lSize + 1];
    // Ū����󤺮e��w�R
    fseek(fp, 0, SEEK_SET);
    fread(lpBuffer, 1, lSize, fp);
    lpBuffer[lSize] = 0x0;
    // �������
    fclose(fp);

    Json::Reader reader;
    Json::Value root;
    reader.parse(lpBuffer, root);

    // ����w�R
    delete []lpBuffer;

    Json::Value data = root["data"];
    if (data.type() == Json::objectValue)
    {
        for (Json::ValueIterator vi = data.begin(); vi != data.end(); vi++)
        {
            OutputLog("���b�M��: %s", vi.key().asCString());

            Json::Value item = data[vi.key().asCString()];

            Json::Value family_name = item["family_name"];
            if (family_name.type() == Json::stringValue)
                OutputLog("%s/family_name: %s", vi.key().asCString(), family_name.asCString());
            else
                OutputLog("%s/family_name Ū������! ����: %d", vi.key().asCString(), family_name.type());

            Json::Value tels = item["tels"];
            if (tels.type() == Json::arrayValue)
            {
                for (size_t i = 0; i < tels.size(); i++)
                {
                    Json::Value tel = tels[i];

                    if (tel.type() == Json::objectValue)
                    {
                        Json::Value value = tel["value"];
                        if (value.type() == Json::stringValue)
                            OutputLog("%s/tels[%d]/value: %s", vi.key().asCString(), i, value.asCString());
                        else
                            OutputLog("%s/tels[%d]/value Ū������! ����: %d", vi.key().asCString(), i, value.type());

                        Json::Value type = tel["type"];
                        if (type.type() == Json::stringValue)
                            OutputLog("%s/tels[%d]/type: %s", vi.key().asCString(), i, type.asCString());
                        else
                            OutputLog("%s/tels[%d]/type Ū������! ����: %d", vi.key().asCString(), i, type.type());

                        Json::Value pref = tel["pref"];
                        if (pref.type() == Json::booleanValue)
                            OutputLog("%s/tels[%d]/pref: %s", vi.key().asCString(), i, pref.asBool()? "true": "false");
                        else
                            OutputLog("%s/tels[%d]/pref Ū������! ����: %d", vi.key().asCString(), i, pref.type());
                    }
                    else
                        OutputLog("%s/tels[%d] Ū������! ����: %d", vi.key().asCString(), i, tel.type());
                }
            }
            else
                OutputLog("%s/tels Ū������! ����: %d", vi.key().asCString(), tels.type());

            Json::Value given_name = item["given_name"];
            if (given_name.type() == Json::stringValue)
                OutputLog("%s/given_name: %s", vi.key().asCString(), given_name.asCString());
            else
                OutputLog("%s/given_name Ū������! ����: %d", vi.key().asCString(), given_name.type());

            Json::Value middle_name = item["middle_name"];
            if (middle_name.type() == Json::stringValue)
                OutputLog("%s/middle_name: %s", vi.key().asCString(), middle_name.asCString());
            else
                OutputLog("%s/middle_name Ū������! ����: %d", vi.key().asCString(), middle_name.type());

            Json::Value customs = item["customs"];
            if (customs.type() == Json::arrayValue)
            {
                for (size_t i = 0; i < customs.size(); i++)
                {
                    OutputLog("���b�M��: %s/customs[%d]", vi.key().asCString(), i);

                    Json::Value custom = customs[i];

                    if (custom.type() == Json::objectValue)
                    {
                        Json::Value value = custom["value"];
                        if (value.type() == Json::stringValue)
                            OutputLog("%s/customs[%d]/value: %s", vi.key().asCString(), i, value.asCString());
                        else
                            OutputLog("%s/customs[%d]/value Ū������! ����: %d", vi.key().asCString(), i, value.type());

                        Json::Value type = custom["type"];
                        if (type.type() == Json::stringValue)
                            OutputLog("%s/customs[%d]/type: %s", vi.key().asCString(), i, type.asCString());
                        else
                            OutputLog("%s/customs[%d]/type Ū������! ����: %d", vi.key().asCString(), i, type.type());
                    }
                    else
                        OutputLog("%s/customs[%d] Ū������! ����: %d", vi.key().asCString(), i, custom.type());
                }
            }
            else
                OutputLog("%s/customs Ū������! ����: %d", vi.key().asCString(), customs.type());
        }
    }
    else
    {
        OutputLog("data Ū������, ����: %d", (int)data.type());
    }
}
//---------------------------------------------------------------------------

