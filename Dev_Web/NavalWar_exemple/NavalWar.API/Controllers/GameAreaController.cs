using Microsoft.AspNetCore.Mvc;
using NavalWar.DTO;
using NavalWar.DTO.Area;
using NavalWar.DTO.WebDTO;
using NavalWar.Utils;

// For more information on enabling Web API for empty projects, visit https://go.microsoft.com/fwlink/?LinkID=397860

namespace NavalWar.API.Controllers
{
    [Route("api/[controller]")]
    [ApiController]
    public class GameAreaController : ControllerBase
    {
        private GameArea _area = new GameArea();

        // GET: api/<GameAreaController>
        [HttpGet]
        public IActionResult GetPlayerBoards()
        {
            _area.AddPLayer();
            List<PlayerDTO> dto = new List<PlayerDTO>();
            foreach (var player in _area.Players)
            {
                dto.Add(new PlayerDTO
                {
                    ShipBoard = player.GetPersonalBoard.ToListArray(),
                    ShotBoard = player.GetShotsBoard.ToListArray()
                });
            }

            return Ok(dto);
        }

        // GET api/<GameAreaController>/5
        [HttpGet("{id}")]
        public string Get(int id)
        {
            return "value";
        }

        // POST api/<GameAreaController>
        [HttpPost]
        public void Post([FromBody] string value)
        {
        }

        // PUT api/<GameAreaController>/5
        [HttpPut("{id}")]
        public void Put(int id, [FromBody] string value)
        {
        }

        // DELETE api/<GameAreaController>/5
        [HttpDelete("{id}")]
        public void Delete(int id)
        {
        }
    }
}
