unit HilbertABC;

interface

uses 
  GraphABC,
  Math;

type
  App = class
  private
    fStartX: integer;
    fStartY: integer;
    fDefaultDepth: integer;
    fDefaultScale: real;
    
    fX: integer;
    fY: integer;
    fWinSize: integer;
    fDepth: integer;
    fStep: integer;
    fScale: real;
  public
    constructor Create(x, y, winSize, depth: integer; scale: real);
    
    /// Рисует кривую Гилберта уровня n
    procedure Draw();
    
    procedure LineBy(dx, dy: integer);
    
    procedure KeyDown(k: integer);
    
    procedure A(i: integer);
    procedure B(i: integer);
    procedure C(i: integer);
    procedure D(i: integer);
  end;

implementation

constructor App.Create(x, y, winSize, depth: integer; scale: real);
begin
  self.fStartX := x;
  self.fStartY := y;
  self.fDefaultDepth := depth;
  self.fDefaultScale := scale;
  
  self.fX := x;
  self.fY := y;
  self.fWinSize := winSize;
  self.fDepth := depth;
  self.fScale := scale;
  
  var step := round(winSize / Power(2, depth));
  if step < 1 then
    self.fStep := 1
  else
    self.fStep := step;
  
  OnKeyDown := self.KeyDown;
  Window.IsFixedSize := True;
  CenterWindow;
end;

procedure App.KeyDown(k: integer);
begin
  case k of
    VK_W:
      if self.fDepth < 18 then 
      begin
        self.fDepth += 1;
        var step := round(self.fWinSize / Power(2, self.fDepth));
        if step < 1 then
          self.fStep := 1
        else
          self.fStep := step;
      end;
    VK_S:
      if self.fDepth > 1 then 
      begin
        self.fDepth -= 1;
        var step := round(self.fWinSize / Power(2, self.fDepth));
        if step < 1 then
          self.fStep := 1
        else
          self.fStep := step;
      end;
    VK_Left: self.fStartX -= 20;
    VK_Right: self.fStartX += 20;
    VK_UP: self.fStartY -= 20;
    VK_Down: self.fStartY += 20;
    VK_Q: self.fScale *= 1.2;
    VK_E: self.fScale /= 1.2;
  end;
  self.Draw;
end;

procedure App.LineBy(dx, dy: integer);
begin
  self.fX += Round(dx * self.fScale);
  self.fY += Round(dy * self.fScale);
  LineTo(self.fX, self.fY);
end;

procedure App.A(i: integer);
begin
  if i > 0 then // БАЗА РЕКУРСИИ: условие прекращения рекурсии (i = 0)
  begin
    // ДЕКОМПОЗИЦИЯ: разбиение задачи на подзадачи меньшего размера
    D(i - 1); // ПАРАМЕТРИЗАЦИЯ: уменьшаем параметр i для рекурсивного вызова
    LineBy(self.fStep, 0);
    A(i - 1);
    LineBy(0, self.fStep);
    A(i - 1);
    LineBy(-self.fStep, 0);
    C(i - 1);
  end;
end;

procedure App.B(i: integer);
begin
  if i > 0 then // БАЗА РЕКУРСИИ
  begin
    // ДЕКОМПОЗИЦИЯ
    C(i - 1); // ПАРАМЕТРИЗАЦИЯ
    LineBy(-self.fStep, 0);
    B(i - 1);
    LineBy(0, -self.fStep);
    B(i - 1);
    LineBy(self.fStep, 0);
    D(i - 1);
  end;
end;

procedure App.C(i: integer);
begin
  if i > 0 then // БАЗА РЕКУРСИИ
  begin
    // ДЕКОМПОЗИЦИЯ
    B(i - 1); // ПАРАМЕТРИЗАЦИЯ
    LineBy(0, -self.fStep);
    C(i - 1);
    LineBy(-self.fStep, 0);
    C(i - 1);
    LineBy(0, self.fStep);
    A(i - 1);
  end;
end;

procedure App.D(i: integer);
begin
  if i > 0 then // БАЗА РЕКУРСИИ
  begin
    // ДЕКОМПОЗИЦИЯ
    A(i - 1); // ПАРАМЕТРИЗАЦИЯ
    LineBy(0, self.fStep);
    D(i - 1);
    LineBy(self.fStep, 0);
    D(i - 1);
    LineBy(0, -self.fStep);
    B(i - 1);
  end;
end;

procedure App.Draw();
begin
  LockDrawing;
  try
    SetWindowSize(self.fWinSize, self.fWinSize);
    SetWindowTitle('Кривая Гилберта');
    ClearWindow(clWhite);
    
    SetPenColor(clDarkBlue);
    
    self.fX := self.fStartX;
    self.fY := self.fStartY;
    
    MoveTo(self.fStartX, self.fStartY);
    A(self.fDepth); // Начальный рекурсивный вызов
  finally
    Redraw;
  end;
end;

end.