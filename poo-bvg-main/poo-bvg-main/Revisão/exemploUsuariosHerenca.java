// Classe base representando um usuário genérico
class User {
    // Atributos comuns a todos os usuários
    protected String username;
    protected String email;

    // Construtor da classe base
    public User(String username, String email) {
        this.username = username;
        this.email = email;
    }

    // Método para exibir informações básicas do usuário
    public void displayInfo() {
        System.out.println("Username: " + username + " | Email: " + email);
    }

    // Método que simula o acesso a um dashboard básico
    public void accessDashboard() {
        System.out.println("Acessando o dashboard do usuário básico.");
    }
}

// Classe Admin, que herda de User e possui privilégios avançados
class Admin extends User {
    private String adminLevel;

    // Construtor da classe Admin
    public Admin(String username, String email, String adminLevel) {
        super(username, email); // Invoca o construtor da classe base
        this.adminLevel = adminLevel;
    }

    // Sobrescrita do método para exibir um dashboard especializado para administradores
    @Override
    public void accessDashboard() {
        System.out.println("Acessando o dashboard do ADMIN com nível: " + adminLevel);
    }

    // Método exclusivo para administradores: gerenciamento de usuários
    public void manageUsers() {
        System.out.println("Gerenciando usuários...");
    }
}

// Classe Moderator, que herda de User e possui privilégios moderadores
class Moderator extends User {

    // Construtor da classe Moderator
    public Moderator(String username, String email) {
        super(username, email);
    }

    // Sobrescrita do método para exibir um dashboard específico para moderadores
    @Override
    public void accessDashboard() {
        System.out.println("Acessando o dashboard do MODERADOR.");
    }

    // Método exclusivo para moderadores: moderação de conteúdo
    public void moderateContent() {
        System.out.println("Moderar conteúdo...");
    }
}

// Classe RegularUser, que representa um usuário comum
class RegularUser extends User {

    // Construtor da classe RegularUser
    public RegularUser(String username, String email) {
        super(username, email);
    }

    // Sobrescrita do método para exibir um dashboard para usuários comuns
    @Override
    public void accessDashboard() {
        System.out.println("Acessando o dashboard do USUÁRIO comum.");
    }
}

// Classe principal que simula o sistema de gerenciamento de usuários
public class UserManagementSystem {
    public static void main(String[] args) {
        // Criação de instâncias de cada tipo de usuário
        User usuarioComum = new RegularUser("joao", "joao@example.com");
        User admin = new Admin("maria", "maria@example.com", "SuperAdmin");
        User moderador = new Moderator("carlos", "carlos@example.com");

        // Exibição de informações e acesso aos dashboards
        System.out.println("---- Usuário Comum ----");
        usuarioComum.displayInfo();
        usuarioComum.accessDashboard();

        System.out.println("\n---- Administrador ----");
        admin.displayInfo();
        admin.accessDashboard();
        // Verificação para acessar método exclusivo do Admin
        if (admin instanceof Admin) {
            ((Admin) admin).manageUsers();
        }

        System.out.println("\n---- Moderador ----");
        moderador.displayInfo();
        moderador.accessDashboard();
        // Verificação para acessar método exclusivo do Moderador
        if (moderador instanceof Moderator) {
            ((Moderator) moderador).moderateContent();
        }
    }
}
