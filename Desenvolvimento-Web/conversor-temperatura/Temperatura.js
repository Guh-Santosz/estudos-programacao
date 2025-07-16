let valor, faren = document.getElementById("Far"), celci = document.getElementById("Cel");
let validacao = false, container = document.getElementById("container");
let calor = document.getElementById("calor"), frio = document.getElementById("frio");
let foto1 = document.getElementById("foto1"), foto2 = document.getElementById("foto2");

function imagem(tomi, aii)
{
    container.style.height = '350px';
    calor.style.display = "none";
    foto1.style.display = "none";
    frio.style.display = "none";
    foto2.style.display = "none";
    
    if(aii)
    {
        if(tomi > 20)
        {
            calor.style.display = "Flex";
            foto1.style.display = "Flex";
        }
        else
        {
            frio.style.display = "Flex";
            foto2.style.display = "Flex";
        }
    }
    else
    {
        if(tomi > 68)
        {
            calor.style.display = "Flex";
            foto1.style.display = "Flex";
        }
        else
        {
            frio.style.display = "Flex";
            foto2.style.display = "Flex";
        }
    }

}

function converter(receba)
{
    if(faren.checked)
    {
        receba = Math.trunc(((receba - 32)/1.8) * 100) / 100;
        document.getElementById("resultado").textContent = `${receba} C°`;
        resultado.style.display = "Flex";
        validacao = true;
    }
    else if(celci.checked)
    {
        receba = Math.trunc((receba * 1.8 + 32)*100) / 100;
        document.getElementById("resultado").textContent = `${receba} F°`;
        resultado.style.display = "Flex";
    }

    imagem(receba, validacao);
}

document.getElementById("converter").onclick = function()
{
    valor = document.getElementById("selecionar").value;

    if(valor == "")
    {
        window.alert("Digite um número válido");
    }
    else if(valor < 999999 && valor > -999999)
    {
        valor = Number(valor);
        converter(valor);
    }
    else
    {
        window.alert("Número muito grande ou muito pequeno");
    }
    
}
