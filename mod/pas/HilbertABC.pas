unit HilbertABC;
interface
uses 
  GraphABC,
  Math;

/// Рисует кривую Гилберта уровня n
procedure Draw(x, y, size, n: integer);
implementation

var
  currentX, currentY: integer;
  step: integer;

procedure LineBy(dx, dy: integer);
begin
  currentX += dx;
  currentY += dy;
  LineTo(currentX, currentY);
end;

procedure A(i: integer); forward;
procedure B(i: integer); forward;
procedure C(i: integer); forward;
procedure D(i: integer); forward;

procedure A(i: integer);
begin
  if i > 0 then
  begin
    D(i - 1);
    LineBy(+step, 0);
    A(i - 1);
    LineBy(0, +step);
    A(i - 1);
    LineBy(-step, 0);
    C(i - 1);
  end;
end;

procedure B(i: integer);
begin
  if i > 0 then
  begin
    C(i - 1);
    LineBy(-step, 0);
    B(i - 1);
    LineBy(0, -step);
    B(i - 1);
    LineBy(+step, 0);
    D(i - 1);
  end;
end;

procedure C(i: integer);
begin
  if i > 0 then
  begin
    B(i - 1);
    LineBy(0, -step);
    C(i - 1);
    LineBy(-step, 0);
    C(i - 1);
    LineBy(0, +step);
    A(i - 1);
  end;
end;

procedure D(i: integer);
begin
  if i > 0 then
  begin
    A(i - 1);
    LineBy(0, +step);
    D(i - 1);
    LineBy(+step, 0);
    D(i - 1);
    LineBy(0, -step);
    B(i - 1);
  end;
end;

procedure Draw(x, y, size, n: integer);
begin
  if n <= 0 then exit;
  
  SetWindowSize(size, size);
  SetWindowTitle('Кривая Гилберта уровня ' + IntToStr(n));
  ClearWindow(clWhite);
  
  SetPenColor(clDarkBlue);

  step := round(size / Power(2, n));
  if step < 1 then
    step := 1;
  
  currentX := x;
  currentY := y;
  
  MoveTo(currentX, currentY);
  A(n);
end;

end.