/*Existe 2 maneiras de dar input em JavaScript

1 - Windows prompt
2 - Hmtl textbox

*/
/*Método 1:*/
/*let username;

username = window.prompt("Qual seu nome: ");

if(username == null)
{
    document.getElementById("teste").textContent = `Digite um nome na caixa de texto`;
}
else
{
    document.getElementById("teste").textContent = `Bem-vindo ${username}!`;
}
*/

let nome;

document.getElementById("Enviar").onclick = function()
{
    nome = document.getElementById("Nome").value;

    if(nome == ``)
    {
        window.alert("Digite seu nome");
    }
    else
    {
        document.getElementById("mensagem").textContent = `Bem-vindo ${nome}!`;
    }
    console.log(`Nome do usuário: ${nome}`);
}
document.getElementById("Resete").onclick = function()
{
    document.getElementById("Nome").value = "";
    document.getElementById("mensagem").textContent = `Bem-vindo!`;
}
