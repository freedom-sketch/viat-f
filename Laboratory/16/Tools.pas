unit Tools;

interface

type
  Anketa = record
  private
    fFIO: string;
    fBirth: DateTime;
    fKurs: integer;
  
  public
    property FIO: string read fFIO;
    property Birth: DateTime read fBirth;
    property BirthStr: string read (fBirth.ToString('dd.MM.yyyy'));
    property Kurs: integer read fKurs;
    
    constructor Create(fio: string; birth: DateTime; kurs: integer);
    constructor Create(randomize: boolean);
    
    procedure FillRandom();
  end;
  
  Toy = record
  public
    Name: string;
    Price: integer;
    MinAge: integer;
    MaxAge: integer;
    
    property AgeRange: string read $'{self.MinAge} - {self.MaxAge}';
  end;

function RandomDate(YearMin, YearMax: integer): DateTime;
function RandomFIO(SurnameSize: integer): string;

implementation

constructor Anketa.Create(fio: string; birth: DateTime; kurs: integer);
begin
  self.fFIO := fio;
  self.fBirth := birth;
  self.fKurs := kurs;
end;

constructor Anketa.Create(randomize: boolean);
begin
  if randomize then
    FillRandom()
  else
  begin
    self.fFIO := '';
    self.fBirth := DateTime.Now;
    self.fKurs := 1;
  end;
end;

procedure Anketa.FillRandom();
begin
  self.fFIO := Tools.RandomFIO(Random(4, 10));
  
  self.fBirth := Tools.RandomDate(1900, 2026);
  self.fKurs := Random(1, 5);
end;

/// Возвращает случайную дату
function RandomDate(YearMin, YearMax: integer): DateTime;
begin
  var Year := Random(YearMin, YearMax);
  var Month := Random(1, 12);
  var DaysInMonth := DateTime.DaysInMonth(Year, Month);
  var Day := Random(1, DaysInMonth);
  
  Result := new DateTime(Year, Month, Day);
end;

///Возвращает случайное псевдоимя
///Пример: Юшщчпэосун К. Ю.
function RandomFIO(SurnameSize: integer): string;
begin
  Result := Chr(Random(1040, 1071));
  
  for var i := 1 to SurnameSize - 1 do
  begin
    Result += Chr(Random(1072, 1104));
  end;
  
  Result += $' {Chr(Random(1040, 1071))}. {Chr(Random(1040, 1071))}.';
end;

initialization
  Randomize;

end.