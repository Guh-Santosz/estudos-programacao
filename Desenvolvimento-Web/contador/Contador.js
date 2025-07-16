let aleatorio = Math.trunc(Math.random()*100);

let numero = 0;

console.log(aleatorio);

document.getElementById("aumentar").onclick = function()
{
    numero++;
    document.getElementById("contagem").textContent = `${numero}`;
}
document.getElementById("diminuir").onclick = function()
{
    if(numero > 0)
    {
        numero--;
        document.getElementById("contagem").textContent = `${numero}`;
    }
    else
    {
        numero = 0;
    }
}
document.getElementById("resetar").onclick = function()
{
    numero = 0;
    document.getElementById("contagem").textContent = `${numero}`;
}