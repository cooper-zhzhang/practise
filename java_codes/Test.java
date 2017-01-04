public class Test{
	public static void main(String args[]){
		Color color = Color.RED;
		color.setName("fdfghfgg");
		System.out.println(color.getIndex());
		System.out.println(Color.getName(3));
		for(Color c : Color.values()){
			System.out.println(c.getName());
		}

	}
}

