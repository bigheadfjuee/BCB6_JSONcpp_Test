object Form1: TForm1
  Left = 290
  Top = 113
  Width = 687
  Height = 532
  Caption = 'Form1'
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -13
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 120
  TextHeight = 16
  object btnTest: TButton
    Left = 464
    Top = 280
    Width = 121
    Height = 49
    Caption = 'btnTest'
    TabOrder = 0
    OnClick = btnTestClick
  end
  object mmoLog: TTntMemo
    Left = 8
    Top = 8
    Width = 441
    Height = 241
    Lines.Strings = (
      'mmoLog')
    TabOrder = 1
  end
  object btnJSON1: TButton
    Left = 464
    Top = 16
    Width = 121
    Height = 49
    Caption = #34389#29702'JSON1'
    TabOrder = 2
    OnClick = btnJSON1Click
  end
  object btnJSON2: TButton
    Left = 464
    Top = 88
    Width = 121
    Height = 49
    Caption = #34389#29702'JSON2'
    TabOrder = 3
    OnClick = btnJSON2Click
  end
  object Memo1: TMemo
    Left = 8
    Top = 272
    Width = 441
    Height = 121
    Lines.Strings = (
      'Memo1')
    TabOrder = 4
  end
end
