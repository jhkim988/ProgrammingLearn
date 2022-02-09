function strokeRoundedRect(ctx, x, y, width, height, radius) {
  widDi = [width, 0, -width, 0];
  heiDi = [0, height, 0, - height];
  
  ctx.beginPath();
  ctx.moveTo(x + radius, y);
  
  prevWid = x;
  prevHei = y;

  for (i = 0; i < 4; i++) {
    ctx.arcTo(prevWid + widDi[i], prevHei + heiDi[i], prevWid + widDi[i] + widDi[(i + 1) % 4], prevHei + heiDi[i] + heiDi[(i + 1) % 4], radius);
    prevWid += widDi[i];
    prevHei += heiDi[i];
  }

  ctx.stroke();
}