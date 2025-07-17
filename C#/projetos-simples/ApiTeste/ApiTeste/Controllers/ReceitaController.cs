using Microsoft.AspNetCore.Mvc;

namespace ApiTeste.Controllers
{
    [ApiController]
    [Route("[controller]")]
    public class ReceitaController : ControllerBase
    {
        private readonly ILogger<ReceitaController> _logger;

        public ReceitaController(ILogger<ReceitaController> logger)
        {
            _logger = logger;
        }

        [HttpGet("{imc}", Name = "GetReceita")]
        public IActionResult Get(double imc)
        {
            String receita;

            if(imc > 25)
            {
                receita = "Carne Assada com ovo";
            }
            else
            {
                receita = "Salada de frutas";
            }

            var objetoResposta = new { Receita = receita };

            return new JsonResult(objetoResposta);
        }
    }
}
