import java.awt.BorderLayout;
import java.awt.CardLayout;
import java.awt.EventQueue;
import java.awt.FlowLayout;
import java.awt.HeadlessException;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.Desktop;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;

public class SlideShow extends JFrame {

	//Declare Variables
	private JPanel slidePane;
	private JPanel textPane;
	private JPanel buttonPane;
	private CardLayout card;
	private CardLayout cardText;
	private JButton btnPrev;
	private JButton btnNext;
	private JLabel lblSlide;
	private JLabel lblTextArea;
	
	// New
	private JLabel hyperlink;
	private String test;
	//
	
	/**
	 * Create the application.
	 */
	public SlideShow() throws HeadlessException {
		initComponent();
	}

	/**
	 * Initialize the contents of the frame.
	 */
	private void initComponent() {
		//Initialize variables to empty objects
		card = new CardLayout();
		cardText = new CardLayout();
		slidePane = new JPanel();
		textPane = new JPanel();
		// I changed the background color to gray because it was really hard to read with the blue.
		textPane.setBackground(Color.GRAY);
		textPane.setBounds(5, 470, 790, 50);
		textPane.setVisible(true);
		buttonPane = new JPanel();
		btnPrev = new JButton();
		btnNext = new JButton();
		lblSlide = new JLabel();
		lblTextArea = new JLabel();
		
		// New
		hyperlink = new JLabel("Have more questions?");
		hyperlink.setForeground(Color.blue.darker());
		hyperlink.setCursor(Cursor.getPredefinedCursor(Cursor.HAND_CURSOR));
		
		hyperlink.addMouseListener(new MouseAdapter() {
			 
            @Override
            public void mouseClicked(MouseEvent e) {
                try {
                    Desktop.getDesktop().browse(new URI("http://www.google.com"));
                } catch (IOException | URISyntaxException e1) {
                    e1.printStackTrace();
                }
            }
 
           
 
        });
		//

		//Setup frame attributes
		setSize(800, 600);
		setLocationRelativeTo(null);
		// Since it's no longer a top 5 destination list, I changed the title to focus on wellness and top detox places
		setTitle("The Top Destinations for Wellness and to Detox");
		getContentPane().setLayout(new BorderLayout(10, 50));
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		//Setting the layouts for the panels
		slidePane.setLayout(card);
		textPane.setLayout(cardText);
		
		//logic to add each of the slides and text
		for (int i = 1; i <= 5; i++) {
			lblSlide = new JLabel();
			lblTextArea = new JLabel();
			lblSlide.setText(getResizeIcon(i));
			lblTextArea.setText(getTextDescription(i));
			slidePane.add(lblSlide, "card" + i);
			textPane.add(lblTextArea, "cardText" + i);
		}

		getContentPane().add(slidePane, BorderLayout.NORTH);
		getContentPane().add(textPane, BorderLayout.CENTER);
		getContentPane().add(hyperlink, BorderLayout.SOUTH);

		buttonPane.setLayout(new FlowLayout(FlowLayout.CENTER, 20, 10));

		btnPrev.setText("Previous");
		btnPrev.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				goPrevious();
			}
		});
		buttonPane.add(btnPrev);

		btnNext.setText("Next");
		btnNext.addActionListener(new ActionListener() {

			@Override
			public void actionPerformed(ActionEvent e) {
				goNext();
			}
		});
		buttonPane.add(btnNext);

		getContentPane().add(buttonPane, BorderLayout.SOUTH);
	}

	/**
	 * Previous Button Functionality
	 */
	private void goPrevious() {
		card.previous(slidePane);
		cardText.previous(textPane);
	}
	
	/**
	 * Next Button Functionality
	 */
	private void goNext() {
		card.next(slidePane);
		cardText.next(textPane);
	}

	/**
	 * Method to get the images
	 */
	private String getResizeIcon(int i) {
		String image = ""; 
		// Here, I added the new images to the resource folder, and then set the URL path to the newly acquired images.
		if (i==1){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/KohSamui.jpg") + "'</body></html>";
		} else if (i==2){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/Glenorchy.jpg") + "'</body></html>";
		} else if (i==3){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/DouroValley.jpg") + "'</body></html>";
		} else if (i==4){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/Bali.jpg") + "'</body></html>";
		} else if (i==5){
			image = "<html><body><img width= '800' height='500' src='" + getClass().getResource("/resources/Phuket.jpg") + "'</body></html>";
		}
		return image;
	}
	
	/**
	 * Method to get the text values
	 */
	private String getTextDescription(int i) {
		String text = ""; 
		// Here, I added the needed text flavor for each destination. In order to keep the screen title font
		// larger and the same as the first example, I kept the font size at 5 for each slide, and then
		// <br> breaks the line, where the next line will revert to the default font size
		if (i==1){
			text = "<html><body><font size='5'>#1 Kamalaya, Koh Samui, Thailand.</font> <br>Built into a hillside, the property overlooks the ocean and is reknown for holistic treatment.</body></html>";
		} else if (i==2){
			text = "<html><body><font size='5'>#2 Aro Ha, Glenorchy, New Zealand.</font> <br>Nestled in NZ's Southern Aps, this retreat overlooks Lake Wakatip, and it completely powered by solar and water.</body></html>";
		} else if (i==3){
			text = "<html><body><font size='5'>#3 Six Senses Douro Valley, Portugal.</font> <br>Tucked away in the vineyards of Douro Valley, the restored 19th century manor is the ultimate escape for yoga and cleanses.</body></html>";
		} else if (i==4){
			text = "<html><body><font size='5'>#4 Fivelements, Bali, Indonesia.</font> <br>Placed in the lush jungles of Bali, this retreat comes with spa treatments, meditation, and a plant-based cuisine.</body></html>";
		} else if (i==5){
			text = "<html><body><font size='5'>#5 Amanpuri, Phuket, Thailand.</font> <br>Overlooking the ocean, Amanpuri houses a two-story spa that sits atop a hill..</body></html>";
		}
		return text;
	}
	
	
	
	/**
	 * Launch the application.
	 */
	public static void main(String[] args) {
		EventQueue.invokeLater(new Runnable() {

			@Override
			public void run() {
				SlideShow ss = new SlideShow();
				ss.setVisible(true);
			}
		});
	}
}