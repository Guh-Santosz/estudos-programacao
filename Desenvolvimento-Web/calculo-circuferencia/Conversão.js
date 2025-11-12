const resposta = document.getElementById("resposta");
const raio = document.getElementById("digite");

document.getElementById("enviar").onclick = function()
{
    if(raio.value == "") resposta.innerHTML = "Digite um raio válido!";
    else
    {
        let raioNumber = Number(raio.value);
        let cicrunf = 2 * Math.PI * raioNumber;
        document.getElementById("resposta").textContent = `Circunferencia: ${cicrunf.toFixed(2)}`;
    }
}
document.getElementById("resetar").onclick = function()
{
    raio.value = "";
    resposta.innerHTML = "Calculo de Circunferência";
}