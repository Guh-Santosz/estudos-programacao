const ganhar = document.getElementById("vitória");
const perder = document.getElementById("derrota");
const empate = document.getElementById("empate");
let computador;

/*Para o computador:

0 = pedra
1 = papel
2 = tesoura

*/

/*Resultados:
1 = vitória
2 = derrota
3 = empate
*/

function none()
{
    for(let i = 1; i <= 6; i++)
    {
        document.getElementById(`pedra${i}`).style.display = "none";
        document.getElementById(`papel${i}`).style.display = "none";
        document.getElementById(`tesoura${i}`).style.display = "none";
    }
}

function sair()
{
    ganhar.style.display = "none";
    perder.style.display = "none";
    empate.style.display = "none";

    none();
}

document.getElementsByClassName("sair")[0].onclick = function()
{
    sair();
}
document.getElementsByClassName("sair")[1].onclick = function()
{
    sair();
}
document.getElementsByClassName("sair")[2].onclick = function()
{
    sair();
}

function jogo(comp, jogador)
{
    switch(jogador)
    {
        case 0:

            if(comp == 0)
            {
                document.getElementById(`pedra6`).style.display = "block";
                document.getElementById(`pedra5`).style.display = "block";
                return 3;
            }
            else if(comp == 1)
            {
                document.getElementById(`pedra3`).style.display = "block";
                document.getElementById(`papel4`).style.display = "block";
                return 2;
            }
            else
            {
                document.getElementById(`pedra1`).style.display = "block";
                document.getElementById(`tesoura2`).style.display = "block";
                return 1;
            }

            break;

        case 1:

            if(comp == 0)
            {
                document.getElementById(`papel1`).style.display = "block";
                document.getElementById(`pedra2`).style.display = "block";
                return 1;
            }
            else if(comp == 1)
            {
                document.getElementById(`papel5`).style.display = "block";
                document.getElementById(`papel6`).style.display = "block";
                return 3;
            }
            else
            {
                document.getElementById(`papel3`).style.display = "block";
                document.getElementById(`tesoura4`).style.display = "block";
                return 2;
            }

            break;

        case 2:

            if(comp == 0)
            {
                document.getElementById(`tesoura3`).style.display = "block";
                document.getElementById(`pedra4`).style.display = "block";
                return 2;
            }
            else if(comp == 1)
            {
                document.getElementById(`tesoura1`).style.display = "block";
                document.getElementById(`papel2`).style.display = "block";
                return 1;
            }
            else
            {
                document.getElementById(`tesoura5`).style.display = "block";
                document.getElementById(`tesoura6`).style.display = "block";
                return 3;
            }

            break;
    }
}
function resultado(a)
{
    switch(a)
    {
        case 1:

        ganhar.style.display = "block";

        break;

        case 2:

        perder.style.display = "block";

        break;

        case 3:

        empate.style.display = "block";
            
        break;
    }
}

document.getElementById("pedra").onclick = function()
{
    computador = Math.floor(Math.random() * 3);
    resultado(jogo(computador, 0));
}
document.getElementById("papel").onclick = function()
{
    computador = Math.floor(Math.random() * 3);
    resultado(jogo(computador, 1));
}
document.getElementById("tesoura").onclick = function()
{
    computador = Math.floor(Math.random() * 3);
    resultado(jogo(computador, 2));
}







none();