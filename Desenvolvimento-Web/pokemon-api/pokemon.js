const button = document.getElementById("botão");

button.onclick = function()
{
    let name = document.getElementById("nome").value;

    if(name == ``)
    {
        window.alert("Digite algo para começar");
    }

    fetch(`https://pokeapi.co/api/v2/pokemon/${name}`)
    .then(response => 
        {
            if(response.status == 404)
            {
                window.alert("Pokémon não encontrado");
            }
            else if(!response.ok)
            {
                throw new Error("Erro na requisição"); 
            }
            return response.json();
        }
    )
    .then(data => 
        {
            document.getElementById("foto").src = data.sprites.other["official-artwork"].front_default;

        }
    )
    .catch(error =>
        {
            console.log("Erro: ", error);
        }
    );

}


