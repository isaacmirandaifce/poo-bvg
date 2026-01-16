

document.addEventListener('DOMContentLoaded', function () {
    const modalEditar = document.getElementById('modalEditar');
    modalEditar.addEventListener('show.bs.modal', function (event) {
        const button = event.relatedTarget;

        const horario = button.getAttribute('data-horario');
        console.log("Horário recebido:", horario);

        document.getElementById('editar-horario-antigo').value = horario;
        document.getElementById('editar-novo-horario').value = horario;
    });

    const excluirModal = document.getElementById('excluirModal');
excluirModal.addEventListener('show.bs.modal', function (event) {
    const button = event.relatedTarget;
    const horario = button.getAttribute('data-horario');
    
    document.getElementById('excluirHorarioInput').value = horario;
    document.getElementById('horarioExclusaoTexto').textContent = horario;
});
});
