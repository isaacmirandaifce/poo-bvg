// Função assíncrona para buscar dados de uma API (simulando o acesso a um banco de dados)
async function fetchData() {
    try {
      // Tenta acessar a API
      const response = await fetch("https://api.exemplo.com/dados");
  
      // Verifica se a resposta do servidor foi bem-sucedida
      if (!response.ok) {
        // Se a resposta não for "ok", lança um erro com o status da resposta
        throw new Error(`Erro na resposta do servidor: ${response.status}`);
      }
  
      // Converte a resposta em JSON
      const data = await response.json();
      console.log("Dados recebidos:", data);
      
      // Exemplo de processamento dos dados na página (atualiza uma tabela ou lista)
      atualizarInterfaceComDados(data);
    } catch (error) {
      // Captura e trata qualquer erro ocorrido na requisição
      console.error("Ocorreu um erro ao acessar o banco de dados:", error);
  
      // Exibe uma mensagem de erro amigável para o usuário
      document.getElementById("errorMessage").textContent =
        "Desculpe, não foi possível carregar os dados no momento. Tente novamente mais tarde.";
    }
  }
  
  // Função que simula a atualização da interface com os dados recebidos
  function atualizarInterfaceComDados(data) {
    // Implementação de exemplo: preencher uma lista na página com os dados recebidos
    const lista = document.getElementById("dataList");
    lista.innerHTML = ""; // Limpa a lista atual
    data.forEach(item => {
      const li = document.createElement("li");
      li.textContent = item.nome;
      lista.appendChild(li);
    });
  }
  
  // Chama a função para buscar os dados quando a página é carregada
  window.onload = fetchData;
  