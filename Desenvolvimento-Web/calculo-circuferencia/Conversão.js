const pi = 3.14159;
let raio;
let cicrunf;

document.getElementById("enviar").onclick = function()
{
    raio = document.getElementById("digite").value;

    if(raio == "")
    {
        window.alert("Digite um raio");
    }
    else
    {
        raio = Number(raio);
        cicrunf = 2 * pi * raio;
        document.getElementById("resposta").textContent = `A circunferência do circulo é de: ${cicrunf} cm`
    }
}
document.getElementById("resetar").onclick = function()
{
    document.getElementById("digite").value = "";
    document.getElementById("resposta").textContent = ``;
}



/*Const não deixa o valor ser mudado
Number converte a variável de string para número*/